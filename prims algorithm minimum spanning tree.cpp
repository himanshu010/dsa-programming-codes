/*
*-----------------------------------------------------------*
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.com )                 |
*-----------------------------------------------------------*
*/

#include <bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define R return

using namespace std;

class Graph
{
    int v;
    list<pair<int, int>> *adj;

  public:
    Graph(int v)
    {
        this->v = v;
        adj = new list<pair<int, int>>[v];
    }
    void addedge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int findMInVERTEX(int *weight, bool *visited, int v)
    {
        int minVertex = -1;
        for (int i = 0; i < v; ++i)
        {
            if (!visited[i] and (minVertex == -1 or weight[i] < weight[minVertex]))
            {
                minVertex = i;
            }
        }
        return minVertex;
    }

    void prims()
    {
        bool *visited = new bool[v];
        int *parent = new int[v];
        int *weight = new int[v];
        for (int i = 0; i < v; ++i)
        {
            visited[i] = false;
            weight[i] = INT_MAX;
        }
        parent[0] = -1;
        weight[0] = 0;
        for (int i = 0; i < v; ++i)
        {
            int minVertex = findMInVERTEX(weight, visited, v);
            visited[minVertex] = true;
            for (auto nbr : adj[minVertex])
            {
                if (!visited[nbr.F])
                {
                    if (weight[nbr.F] > nbr.S)
                    {
                        parent[nbr.F] = minVertex;
                        weight[nbr.F] = nbr.S;
                    }
                }
            }
        }

        for (int i = 1; i < v; ++i)
        {
            cout << i << "---" << parent[i] << " with weight = " << weight[i] << endl;
        }
    }
};

void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addedge(x, y, w);
    }
    g.prims();
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t; cin >> t; while (t--)
    {
        solve();
    }
}