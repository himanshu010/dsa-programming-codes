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
class Solution
{
  public:
    bool ans = 1;
    int check(TreeNode *cur)
    {
        int l = 0, r = 0;

        if (cur->left)
        {
            l = check(cur->left);
        }
        if (cur->right)
        {
            r = check(cur->right);
        }

        if (abs(l - r) > 1)
        {
            ans = false;
            return 0;
        }
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return 1;
        }
        check(root);
        return ans;
    }
};