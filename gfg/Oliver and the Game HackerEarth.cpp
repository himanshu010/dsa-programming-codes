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

vvi graph;
vb visited;
vi startTime, endTime;
int timer = 0;

void addEdge(int l, int r)
{
    graph[l].pb(r);
    graph[r].pb(l);
}

void dfs(int cur)
{

    visited[cur] = 1;
    startTime[cur] = timer;
    timer++;

    for (auto child : graph[cur])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }

    endTime[cur] = timer;
    timer++;
}

bool check(int l, int r)
{
    return (startTime[l] < startTime[r] && endTime[r] < endTime[l]);
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    graph.resize(n + 1);
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), 0);

    startTime.resize(n + 1);
    endTime.resize(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int l, r;
        cin >> l >> r;
        addEdge(l, r);
    }
    dfs(1);
    int q;
    cin >> q;

    while (q--)
    {
        bool flag;
        cin >> flag;
        int l, r;
        cin >> l >> r;
        if (!flag)
        {
            if (check(l, r))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            if (check(r, l))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}
int main()
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