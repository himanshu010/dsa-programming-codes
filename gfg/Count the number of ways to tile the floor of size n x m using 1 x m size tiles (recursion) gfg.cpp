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

int allWays(int n, int m, vvi &dp)
{
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (n == 1 or n == 0)
    {
        return 1;
    }

    int a = allWays(n - 1, m, dp);
    int b = 0;
    if (n >= m)
    {
        b = allWays(n - m, m, dp);
    }
    return dp[n][m] = a + b;
}
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vvi dp(n + 1, vi(m + 1, -1));
    cout << allWays(n, m, dp) << endl;
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