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

vvi graph;
vb visited;
int total = 0;

void bfs(int src)
{
    visited[src] = 1;
    queue<int> qu;
    qu.push(src);
    while (!qu.empty())
    {
        int cur = qu.front();
        total += 1;
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

void addEdge(int l, int r)
{
    graph[l].pb(r);
    graph[r].pb(l);
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    graph.resize(n);
    visited.resize(n);
    fill(visited.begin(), visited.end(), 0);

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        addEdge(l, r);
    }
    vi students;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            total = 0;
            bfs(i);
            students.pb(total);
        }
    }

    int no = students.size();
    vi suffix(no);
    suffix[no - 1] = students[no - 1];

    for (int i = no - 2; i >= 0; --i)
    {
        suffix[i] = suffix[i + 1] + students[i];
    }

    for (int i = 0; i < no - 1; ++i)
    {
        ans += (students[i] * suffix[i + 1]);
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