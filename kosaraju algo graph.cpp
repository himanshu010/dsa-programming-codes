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

const int N = 100005, M = 22;
vector<int> gr[N], grr[N];
vector<int> order;
int vis[N];
int comp[N];
vector<int> in_comp[N];

void dfs(int curr)
{
    vis[curr] = 1;
    for (auto child : gr[curr])
    {
        if (!vis[child])
            dfs(child);
    }
    // cout << curr << "-----" << endl;
    order.pb(curr);
}

void dfs_reverse(int curr, int col)
{
    // cout << col << "------" << endl;
    comp[curr] = col;
    in_comp[col].pb(curr);
    vis[curr] = 1;
    for (auto child : grr[curr])
    {
        if (!vis[child])
            dfs_reverse(child, col);
    }
    order.pb(curr);
}

void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        gr[x].pb(y);
        grr[y].pb(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    int col = 1;
    for (i = n; i >= 1; i--)
    {
        if (!vis[order[i]])
        {
            // cout << col << endl;
            dfs_reverse(order[i], col);
            col++;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " -> " << comp[i] << '\n';
    }
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
    // int t;cin>>t;while(t--)
    {
        solve();
    }
}