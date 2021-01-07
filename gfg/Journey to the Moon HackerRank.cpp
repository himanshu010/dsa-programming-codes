int TreeSize = 0;
vector<vector<int>> graph(100005);
vector<bool> visited(100005, 0);

void addEdge(int l, int r)
{
    graph[l].pb(r);
    graph[r].pb(l);
}

void dfs(int src)
{
    TreeSize++;
    visited[src] = 1;

    for (auto child : graph[src])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut)
{
    int m = astronaut.size();
    for (int i = 0; i < m; i++)
    {
        addEdge(astronaut[i][0], astronaut[i][1]);
    }
    vector<int> sizes;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            TreeSize = 0;
            dfs(i);
            sizes.pb(TreeSize);
        }
    }
    int number = sizes.size();
    vector<int> suffix_sum(number);
    suffix_sum[number - 1] = sizes[number - 1];
    for (int i = number - 2; i >= 0; i--)
    {
        suffix_sum[i] = suffix_sum[i + 1] + sizes[i];
    }

    int ans = 0;
    for (int i = 0; i < number - 1; i++)
    {
        ans += sizes[i] * suffix_sum[i + 1];
    }
    return ans;
}