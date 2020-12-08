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
using namespace std;

int attempts_needed(int n, int k, vvi &dp) {
    if (n <= 1 or k <= 1) {
        return dp[n][k];
    }
    int minimum = INT_MAX;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= k; ++j)
        {
            int minimum = INT_MAX;
            for (int l = 1; l <= j; ++l)
            {
                minimum = min(minimum, max(dp[i - 1][j - l], dp[i][l - 1]));
            }
            dp[i][j] = minimum + 1;
        }
    }
    return dp[n][k];
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    vector<vector<int>>dp(n + 1, vector<int>(k + 1));
    for (int i = 0; i <= k; ++i)
    {
        dp[0][i] = 0;
        dp[1][i] = i;
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    cout << attempts_needed(n, k, dp);



}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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