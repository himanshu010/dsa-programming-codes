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
#define PQ priority_queue
using namespace std;

vector<P> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool check(int r, int c, int n, vvi &chessboard)
{
    if (r >= 0 and c >= 0 and r < n and c < n and chessboard[r][c] == -1)
    {
        return true;
    }
    return false;
}

bool getOrder(int r, int c, int order, int n, vvi &chessboard)
{

    if (order == n * n)
    {
        return true;
    }

    for (auto x : moves)
    {
        int next_r = r + x.F;
        int next_c = c + x.S;

        if (check(next_r, next_c, n, chessboard))
        {
            chessboard[next_r][next_c] = order;
            if (getOrder(next_r, next_c, order + 1, n, chessboard))
            {
                return true;
            }
            else
            {
                chessboard[next_r][next_c] = -1;
            }
        }
    }
    return false;
}

void solve(int tc)
{
    int i, j, k, m, ans = 0, cnt = 0, sum = 0;
    int n;
    cin >> n;
    vector<vector<int>> chessboard(n, vi(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            chessboard[i][j] = -1;
        }
    }
    chessboard[0][0] = 0;
    if (getOrder(0, 0, 1, n, chessboard))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << chessboard[i][j] << ' ';
            }
            cout << endl;
        }
    }
    else
    {
        cout << -1 << endl;
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