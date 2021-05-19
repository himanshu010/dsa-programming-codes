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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q) {
            return true;
        }
        if ((!p and q) or (p and !q)) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }

        bool ans1 = 1;
        bool ans2 = 1;
        if ((p->left and !q->left) or (p->right and !q->right) or (!p->left and q->left) or (!p->right and q->right)) {
            return false;
        }
        if (p->left and q->left)ans1 = isSameTree(p->left, q->left);
        if (p->right and q->right) ans2 = isSameTree(p->right, q->right);


        return ans1 & ans2;
    }
};