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

vector<pair<int, int>> moves = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

bool isValid(int r, int c, int n, int m, vector<vector<char>> &grid)
{
    return (r >= 0 and r < n and c >= 0 and c < m and grid[r][c] == '1');
}

void bfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    int n = grid.size();
    int m = grid[0].size();
    visited[r][c] = 1;
    queue<pair<int, int>> qu;

    qu.push({r, c});
    while (!qu.empty())
    {
        pair<int, int> cur = qu.front();
        qu.pop();
        for (auto x : moves)
        {
            if (isValid(cur.first + x.first, cur.second + x.second, n, m, grid) and
                !visited[cur.first + x.first][cur.second + x.second])
            {
                visited[cur.first + x.first][cur.second + x.second] = 1;
                qu.push({cur.first + x.first, cur.second + x.second});
            }
        }
    }
}

int numIslands(vector<vector<char>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] and grid[i][j] == '1')
            {
                cnt += 1;
                bfs(i, j, grid, visited);
            }
        }
    }
    return cnt;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    cout << numIslands(a);
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