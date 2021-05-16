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
#define PQ priority_queue
using namespace std;

vvi graph;
vi visited_time, low_time, parent;

int tt = 0;

void dfs(int cur, int par)
{
    parent[cur] = par;
    visited_time[cur] = low_time[cur] = tt;
    tt += 1;
    for (auto x : graph[cur])
    {
        if (visited_time[x] == -1)
        {
            dfs(x, cur);
            low_time[cur] = min(low_time[cur], low_time[x]);

            if (visited_time[cur] < low_time[x])
            {
                cout << cur << ' ' << x << endl;
            }
        }
        else if (x != parent[cur])
        {
            low_time[cur] = min(low_time[cur], low_time[x]);
        }
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    graph.resize(n + 1);
    visited_time.resize(n + 1);
    low_time.resize(n + 1);
    parent.resize(n + 1);

    fill(visited_time.begin(), visited_time.end(), -1);
    fill(low_time.begin(), low_time.end(), INT_MAX);
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        graph[l].push_back(r);
        graph[r].push_back(l);
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited_time[i] == -1)
        {
            dfs(i, -1);
        }
    }
}
int32_t main()
{
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