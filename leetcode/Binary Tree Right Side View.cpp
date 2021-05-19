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
    vector<int> ans;
    void bfs(TreeNode *root)
    {
        vector<bool> visited(100, 0);
        visited[0] = 1;
        queue<pair<TreeNode *, int>> qu;
        qu.push({root, 0});
        while (!qu.empty())
        {
            TreeNode *cur = qu.front().first;
            int row = qu.front().second;

            if (!visited[row])
            {
                ans.push_back(cur->val);
                visited[row] = 1;
            }
            qu.pop();

            if (cur->right != NULL)
            {
                qu.push({cur->right, row + 1});
            }
            if (cur->left != NULL)
            {
                qu.push({cur->left, row + 1});
            }
        }
    }
    vector<int> rightSideView(TreeNode *root)
    {
        ans.clear();
        if (root == NULL)
        {
            return ans;
        }
        ans.push_back(root->val);
        bfs(root);
        return ans;
    }
};