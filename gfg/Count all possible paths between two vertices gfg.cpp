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

void addEdge(int l, int r)
{
    graph[l].pb(r);
}

int bfs(int src, int dst)
{
    int total = 0;
    queue<int> qu;
    qu.push(src);
    while (!qu.empty())
    {
        int cur = qu.front();
        if (cur == dst)
        {
            total += 1;
        }
        qu.pop();
        for (auto nbr : graph[cur])
        {
            qu.push(nbr);
        }
    }
    return total;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    graph.clear();
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        addEdge(l, r);
    }

    int cur, dst;
    cin >> cur >> dst;
    cout << bfs(cur, dst) << endl;
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