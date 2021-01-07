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
int posi[] = {-1, 0, 1, 0};
int posj[] = {0, 1, 0, -1};
vector<vector<int>> graph(1000005);
vector<bool> visited(1000005, 0);
void addEdge(vector<vector<int>> &a, int r, int c, int n, int m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (r + posi[i] >= 0 and r + posi[i] < n and c + posj[i] >= 0 and c + posj[i] < m)
        {
            if (a[r + posi[i]][c + posj[i]] != -1)
            {
                graph[a[r][c]].pb(a[r + posi[i]][c + posj[i]]);
            }
        }
    }
}

int total = 0;
void dfs(int src)
{
    // total += 1;
    visited[src] = 1;

    queue<int> qu;
    qu.push(src);
    while (!qu.empty())
    {
        total += 1;
        int cur = qu.front();
        qu.pop();
        for (auto nbr : graph[cur])
        {
            if (!visited[nbr])
            {
                visited[nbr] = 1;
                qu.push(nbr);
            }
        }
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            bool temp;
            cin >> temp;
            if (temp)
            {
                mat[i][j] = cnt;
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mat[i][j] != -1)
            {
                addEdge(mat, i, j, n, m);
            }
        }
    }

    while (k--)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        total = 0;
        if (mat[r][c] != -1)
        {
            if (!visited[mat[r][c]])
            {
                dfs(mat[r][c]);
            }
        }
        cnt -= total;
        cout << cnt << endl;
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
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}