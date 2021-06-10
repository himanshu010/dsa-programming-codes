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
    int withRootSum(TreeNode *cur, int sum)
    {
        if (!cur)
        {
            return 0;
        }

        sum -= cur->val;
        int res = 0;
        if (sum == 0)
        {
            res += 1;
        }

        return res + withRootSum(cur->left, sum) + withRootSum(cur->right, sum);
    }

    int sumHelper(TreeNode *root, int sum)
    {
        if (!root)
        {
            return 0;
        }
        return sumHelper(root->left, sum) + sumHelper(root->right, sum) + withRootSum(root, sum);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        return sumHelper(root, targetSum);
    }
};