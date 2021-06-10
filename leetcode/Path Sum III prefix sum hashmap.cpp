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
    unordered_map<int, int> mp;
    int ans = 0;
    void checkSum(TreeNode *cur, int target, int sum)
    {
        if (mp.count(sum + cur->val - target))
        {
            ans += mp[sum + cur->val - target];
        }
        mp[sum + cur->val] += 1;
        if (sum + cur->val == target)
        {
            ans += 1;
        }
        if (cur->left)
        {
            checkSum(cur->left, target, sum + cur->val);
            mp[sum + cur->val + cur->left->val] -= 1;
        }
        if (cur->right)
        {
            checkSum(cur->right, target, sum + cur->val);
            mp[sum + cur->val + cur->right->val] -= 1;
        }
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        checkSum(root, targetSum, 0);
        return ans;
    }
};