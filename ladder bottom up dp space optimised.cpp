/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|                       (himanshu010)                       |
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
#define R return

using namespace std;

int ways_bottomUp_SpaceOptimised(int n, int k)
{
    int dp[100] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        int ans = 2 * dp[i - 1];
        if ((i - k - 1) >= 0)
        {
            ans -= dp[i - k - 1];
        }
        dp[i] = ans;
    }

    for (auto x : dp)
    {
        cout << x << " ";
    }
    cout << endl;
    return dp[n];
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
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> k;
        cout << ways_bottomUp_SpaceOptimised(n, k);
    }
}