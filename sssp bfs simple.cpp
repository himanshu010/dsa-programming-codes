/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|     ( website: himanshu010.github.io/Portfolio_website )  |
|                                                           |
|                                                           |
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

using namespace std;

vector<vector<int>> graph(100005);
vector<bool> visited(100005, 0);

vector<int> dist(100005, INT_MAX);
vector<int> parent(100005, 0);

void addEdge(int l, int r)
{
    graph[l].pb(r);
}

void sssp(int src)
{
    dist[src] = 0;
    queue<int> qu;
    qu.push(src);

    while (!qu.empty())
    {
        int cur = qu.front();
        qu.pop();
        cout << "distance of " << cur << " from source is " << dist[cur] << endl;
        for (auto x : graph[cur])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                qu.push(x);
                parent[x] = cur;
                dist[x] = dist[parent[x]] + 1;
            }
        }
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        addEdge(l, r);
    }

    sssp(0);
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
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}