/*
*-----------------------------------------------------------*
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.com )                 |
*-----------------------------------------------------------*
*/
#include <bits/stdc++.h>
#define moduli 1000000007
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

vector<vector<int>> graph(100005);
vector<bool> visited(100005, 0);

vector<int> posi = {-2, -2, -1, 1, 2, 2, 1, -1};
vector<int> posj = {-1, 1, 2, 2, 1, -1, -2, -2};

int factorial(int n)
{
    if (n == 0 or n == 1)
    {
        return 1;
    }
    return (n * factorial(n - 1)) % moduli;
}

int total = 0;

void dfs(int cur)
{
    total += 1;
    visited[cur] = 1;
    for (auto child : graph[cur])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

void addEdge(int r, int c, vector<vector<int>> &a, int n, int m)
{
    for (int i = 0; i < 8; ++i)
    {
        if (posi[i] + r >= 0 and posi[i] + r < n and posj[i] + c >= 0 and posj[i] + c < m)
        {
            if (a[r + posi[i]][c + posj[i]] != -1)
            {
                graph[a[r][c]].pb(a[r + posi[i]][c + posj[i]]);
            }
        }
    }
}

void solve(int tc)
{
    graph.clear();
    graph.resize(100005);
    visited.clear();
    visited.resize(100005);
    fill(visited.begin(), visited.end(), 0);
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m, -1));
    for (int i = 0; i < k; ++i)
    {
        int r, c;
        cin >> r >> c;
        mat[r - 1][c - 1] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mat[i][j] != -1)
            {
                addEdge(i, j, mat, n, m);
            }
        }
    }

    int res = 1;
    for (int i = 0; i < k; ++i)
    {
        if (!visited[i])
        {
            total = 0;
            dfs(i);
            res = (res * factorial(total)) % moduli;
        }
    }

    cout << res << endl;
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
    int t;
    cin >> t;
    while (t--)
    {
        solve(tc);
        tc++;
    }
}