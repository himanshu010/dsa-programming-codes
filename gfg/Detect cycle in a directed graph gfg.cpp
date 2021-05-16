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
vb visited;
vi tillNow;
bool loop = 0;

void addEdge(int l, int r)
{
    graph[l].pb(r);
}

void dfs(int cur)
{
    tillNow[cur] = 1;
    visited[cur] = 1;
    for (auto child : graph[cur])
    {
        if (tillNow[child])
        {
            loop = 1;
            return;
        }
        else
        {
            dfs(child);
        }
    }
    tillNow[cur] = 0;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    graph.clear();
    graph.resize(n + 1);

    visited.clear();
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), 0);

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        addEdge(l, r);
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            tillNow.clear();
            tillNow.resize(n + 1);
            fill(tillNow.begin(), tillNow.end(), 0);
            dfs(i);
            if (loop)
            {
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No" << endl;
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