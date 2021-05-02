/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.codes )               |
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
#define PQ priority_queue
using namespace std;

bool bfs(int src, int dest, vvi &graph, int n)
{
    queue<int> qu;
    qu.push(src);
    vb visited(n, 0);
    while (!qu.empty())
    {
        int cur = qu.front();
        if (cur == dest)
        {
            return true;
        }
        visited[cur] = 1;
        qu.pop();
        for (auto x : graph[cur])
        {
            if (!visited[x])
            {
                qu.push(x);
            }
        }
    }
    return false;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i)
    {
        int l, r, w;
        cin >> l >> r >> w;
        graph[l].pb(r);
        graph[r].pb(l);
    }

    cin >> k >> j;
    if (bfs(k, j, graph, n))
    {
        cout << "true" << endl;
        return;
    }
    cout << "false" << endl;
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