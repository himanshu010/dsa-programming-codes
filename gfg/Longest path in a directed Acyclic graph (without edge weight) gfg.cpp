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
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> dist;
int mx = 0;

void addEdge(int l, int r)
{
    graph[l].pb(r);
}

int longestPathBFS(int src)
{
    unordered_map<int, int> mp;
    int mm = 0;
    visited[src] = 1;

    queue<P> qu;
    qu.push({src, 0});
    dist[src] = 0;

    while (!qu.empty())
    {
        P cur = qu.front();
        qu.pop();
        for (auto nbr : graph[cur.F])
        {
            dist[nbr] = max(dist[nbr], cur.S + 1);
            qu.push({nbr, dist[nbr]});
            mm = max(dist[nbr], mm);
        }
    }

    return mm;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), 0);

    dist.resize(n + 1);
    fill(dist.begin(), dist.end(), -1);

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        addEdge(l - 1, r - 1);
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            mx = max(mx, longestPathBFS(i));
        }
    }

    cout << mx << endl;
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