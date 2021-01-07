#define pb push_back

vector<bool> visited;
vector<int> order;
void dfs(int cur, vector<int> graph[], bool flag)
{
    visited[cur] = 1;
    for (auto child : graph[cur])
    {
        if (!visited[child])
        {
            dfs(child, graph, flag);
        }
    }
    if (flag)
    {
        order.pb(cur);
    }
}

int kosaraju(int n, vector<int> adj[])
{
    order.clear();
    visited.clear();
    visited.resize(n);
    fill(visited.begin(), visited.end(), 0);
    vector<int> rev[n];
    for (int i = 0; i < n; i++)
    {
        for (auto x : adj[i])
        {
            rev[x].pb(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, 1);
        }
    }
    int sum = 0;

    visited.clear();
    visited.resize(n);
    fill(visited.begin(), visited.end(), 0);
    reverse(order.begin(), order.end());
    for (auto x : order)
    {
        if (!visited[x])
        {
            dfs(x, rev, 0);
            sum += 1;
        }
    }
    return sum;
}