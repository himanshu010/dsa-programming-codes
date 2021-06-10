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
    vector<vector<int>> ans;

    void findPath(TreeNode *cur, vector<int> &path, int sum, int target)
    {

        if (!cur->left and !cur->right)
        {
            if (sum == target)
            {
                ans.push_back(path);
            }
        }

        if (cur->left)
        {
            path.push_back(cur->left->val);
            findPath(cur->left, path, sum + cur->left->val, target);
            path.pop_back();
        }
        if (cur->right)
        {
            path.push_back(cur->right->val);
            findPath(cur->right, path, sum + cur->right->val, target);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return ans;
        }

        vector<int> path;
        path.push_back(root->val);
        findPath(root, path, root->val, targetSum);
        return ans;
    }
};