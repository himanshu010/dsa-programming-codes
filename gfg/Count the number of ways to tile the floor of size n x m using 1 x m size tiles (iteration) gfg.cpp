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
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        if (i - m >= 0)
        {
            dp[i] = (dp[i - 1] + dp[i - m]) % moduli;
        }
        else
        {
            dp[i] = dp[i - 1] % moduli;
        }
    }
    cout << dp[n] << endl;
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