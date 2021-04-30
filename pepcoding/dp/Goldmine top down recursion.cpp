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
#include<bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define PQ priority_queue
using namespace std;

int findSum(int row, vvi &aa, int col, int dst, int n, vvi&dp) {
    // cout << col << ' ' << dst << endl;

    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    if (col == dst) {
        return dp[row][col] = aa[row][col];
    }
    int a = 0, b = 0, c = 0;
    if (row > 0) {
        a = findSum(row - 1, aa, col + 1, dst, n, dp);
    }
    if (row < n - 1) {
        b = findSum(row + 1, aa, col + 1, dst, n, dp);
    }
    c = findSum(row, aa, col + 1, dst, n, dp);

    return dp[row][col] = max(a, max(b, c)) + aa[row][col];
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    vvi dp(n, vi(m, -1));

    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, findSum(i, a, 0, m - 1, n, dp));
    }


    cout << ans << endl;

}
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}