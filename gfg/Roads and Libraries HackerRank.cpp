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

vector<vector<int>> graph(100005);
vector<bool> visited(100005, 0);
int TreeSize = 0;
void addEgde(int l, int r)
{
    graph[l].pb(r);
    graph[r].pb(l);
}

void dfs(int src)
{
    visited[src] = 1;
    TreeSize++;

    for (auto child : graph[src])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

void solve(int tc)
{
    graph.clear();
    graph.resize(100005);
    visited.clear();
    visited.resize(100005);
    TreeSize = 0;
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0, lib, road;
    cin >> n >> m >> lib >> road;
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        addEgde(l - 1, r - 1);
    }

    if (lib <= road)
    {
        cout << n * lib << endl;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            cnt++;
            TreeSize = 0;
            dfs(i);
            ans += (TreeSize - 1) * road;
        }
    }

    ans += lib * cnt;
    cout << ans << endl;
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
    int t;
    cin >> t;
    while (t--)
    {
        solve(tc);
        tc++;
    }
}