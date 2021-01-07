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
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define um unordered_map
using namespace std;

vvi graph;
vb visited;

void addEdge(int l, int r)
{
    graph[l].pb(r);
    graph[r].pb(l);
}

void bfs(int src)
{
    queue<int> qu;
    qu.push(src);
    visited[src] = 1;
    while (!qu.empty())
    {
        int cur = qu.front();
        qu.pop();
        for (auto nbr : graph[cur])
        {
            if (!visited[nbr])
            {
                qu.push(nbr);
                visited[nbr] = 1;
            }
        }
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;

    graph.resize(n);
    visited.resize(n);
    fill(visited.begin(), visited.end(), 0);

    vvc mat(n, vc(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mat[i][j] == 'Y')
            {
                addEdge(i, j);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            ans++;
            bfs(i);
        }
    }
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
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}