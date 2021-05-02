class Solution
{
  public:
    vector<int> ans;
    void bfs(Node *root)
    {
        vector<bool> visited(100005, 0);
        visited[0] = 1;
        queue<pair<Node *, int>> qu;
        qu.push({root, 0});
        while (!qu.empty())
        {
            Node *cur = qu.front().first;
            int row = qu.front().second;
            if (visited[row] == 0)
            {
                ans.push_back(cur->data);
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
    vector<int> rightView(Node *root)
    {
        ans.clear();
        if (root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);
        bfs(root);
        return ans;
    }
};
