/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int findMaxDepth(TreeNode* cur) {
        if (!cur->left and !cur->right) {
            return 1;
        }

        int l = 0, r = 0;
        if (cur->left) {
            l = findMaxDepth(cur->left);
        }
        if (cur->right) {
            r = findMaxDepth(cur->right);
        }

        return max(l, r) + 1;
    }

    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return findMaxDepth(root);
    }
};