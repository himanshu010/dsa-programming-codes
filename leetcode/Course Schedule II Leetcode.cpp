#define pb push_back
vector<vector<int>> graph(2001);
vector<bool> visited(2001, 0);
vector<int> required(2001, 0);
vector<int> ans;
class Solution
{
  public:
    void addEdge(int l, int r)
    {
        graph[l].pb(r);
        required[r]++;
    }

    void dfs(int src)
    {
        visited[src] = 1;
        ans.pb(src);

        for (auto child : graph[src])
        {
            required[child]--;
            if (required[child] <= 0 and !visited[child])
            {
                dfs(child);
            }
        }
    }

    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {
        graph.clear();
        graph.resize(2001);
        visited.clear();
        visited.resize(2001);
        fill(visited.begin(), visited.end(), 0);
        required.clear();
        required.resize(2001);
        fill(required.begin(), required.end(), 0);

        ans.clear();
        for (auto x : prerequisites)
        {
            addEdge(x[1], x[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] and !required[i])
            {
                dfs(i);
            }
        }
        if (ans.size() != n)
        {
            return {};
        }

        return ans;
    }
};