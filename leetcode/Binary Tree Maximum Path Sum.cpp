class Solution
{
  public:
    int ans = INT_MIN;
    int findMaxPath(TreeNode *cur)
    {
        if (!cur->right and !cur->left)
        {
            ans = max(ans, cur->val);
            return cur->val;
        }
        int l = 0;
        int r = 0;

        if (cur->left)
        {
            l = findMaxPath(cur->left);
        }
        if (cur->right)
        {
            r = findMaxPath(cur->right);
        }
        ans = max({ans, r + cur->val, r + cur->val + l, cur->val + l, cur->val});
        return max({cur->val, cur->val + r, cur->val + l});
    }

    int maxPathSum(TreeNode *root)
    {
        findMaxPath(root);
        return ans;
    }
};