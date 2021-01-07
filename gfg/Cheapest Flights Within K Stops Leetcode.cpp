#define pb push_back
#define F first
#define S second
vector<vector<pair<int, int>>> graph(101);
vector<bool> visited(101, 0);
int ans = INT_MAX;

class Solution
{
  public:
    void dfs(int src, int sum, int k, int dest, int cnt)
    {
        if (k - 1 > cnt or sum > ans)
        {
            return;
        }
        if (src == dest)
        {
            if (k - 1 <= cnt and sum < ans)
            {
                ans = sum;
            }
            return;
        }
        visited[src] = true;

        for (auto child : graph[src])
        {
            if (!visited[child.F] and sum + child.S < ans)
            {
                dfs(child.F, sum + child.S, k + 1, dest, cnt);
            }
        }
        visited[src] = false;
    }
    void addEdge(int l, int r, int w)
    {
        graph[l].pb({r, w});
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        ans = INT_MAX;
        graph.clear();
        graph.resize(101);

        for (int i = 0; i < flights.size(); i++)
        {
            addEdge(flights[i][0], flights[i][1], flights[i][2]);
        }

        dfs(src, 0, 0, dst, K);
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};