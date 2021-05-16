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
vector<int> gr[N];

void bfs(int src, int n, int &ans)
{
    vector<int> dis(n + 1, INT_MAX);

    queue<int> Q;
    Q.push(src);
    dis[src] = 0;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (auto neighbour : gr[cur])
        {
            if (dis[neighbour] == INT_MAX)
            {
                // neighbour not visited
                dis[neighbour] = dis[cur] + 1;
                Q.push(neighbour);
            }
            else
            {
                // backedge
                if (dis[neighbour] >= dis[cur])
                {
                    ans = min(ans, dis[neighbour] + dis[cur] + 1);
                }
            }
        }
    }
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
        gr[y].pb(x);
    }
    ans = n + 1;
    // cout << ans << endl;
    for (int i = 0; i < m; ++i)
    {
        bfs(i, n, ans);
    }
    if (ans == n + 1)
    {
        cout << "no cycle" << endl;
    }
    else
    {
        cout << "shortest cycle have a length of: " << ans << endl;
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