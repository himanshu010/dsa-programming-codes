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

vector<vector<P>> graph;
vector<P> required;

class compare
{
  public:
    bool operator()(P a, P b)
    {
        return a.F < b.F;
    }
};

void addEdge(int l, int r, int w)
{
    graph[l].pb({r, w});
    required[r].F += 1;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;

    graph.resize(n);
    required.resize(n);
    for (int i = 0; i < n; ++i)
    {
        required[i] = {0, i};
    }

    for (int i = 0; i < m; ++i)
    {
        int l, r, w;
        cin >> l >> r >> w;
        addEdge(l, r, w);
    }

    sort(required.begin(), required.end(), compare());
    vector<int> maxDistance(n, INT_MIN);

    for (auto x : required)
    {
        int cur = x.S;
        if (x.F == 0)
        {
            maxDistance[cur] = 0;
        }
        for (auto child : graph[cur])
        {
            maxDistance[child.F] = max(maxDistance[child.F], child.S + maxDistance[cur]);
        }
    }

    int mx = INT_MIN;
    for (auto x : maxDistance)
    {
        mx = max(mx, x);
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