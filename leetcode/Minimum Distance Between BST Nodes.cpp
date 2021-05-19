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
    int prev = -1;
    int ans = INT_MAX;
    void minDif(TreeNode* root) {
        if (root->left) {
            minDif(root->left);
        }
        cout << root->val << ' ' << prev << endl;
        if (prev != -1) {
            ans = min(ans, abs(root->val - prev));
        }

        prev = root->val;
        if (root->right) {
            minDif(root->right);
        }
    }

    int minDiffInBST(TreeNode* root) {
        minDif(root);
        return ans;
    }
};