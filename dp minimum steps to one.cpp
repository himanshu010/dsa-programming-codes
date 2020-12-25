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
int cased = 1;

int minstepsTOP_DOWN(int n, int dp[])
{
    // Base case
    if (n == 1)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    // Rec Case
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if (n % 3 == 0)
    {
        op1 = minsteps(n / 3, dp) + 1;
    }
    if (n % 2 == 0)
    {
        op2 = minsteps(n / 2, dp) + 1;
    }
    op3 = minsteps(n - 1, dp) + 1;

    int ans = min(min(op1, op2), op3);
    dp[n] = ans;
    return dp[n];
}

// int minstepsBOTTOM_UP(int n) {
//     vector<int> dp;
//     dp.pb(0);
//     dp.pb(0);
//     dp.pb(1);
//     dp.pb(1);
//     for (int i = 4; i <= n; ++i)
//     {
//         int minimum;
//         if (i % 2 == 0 && i % 3 == 0) {
//             minimum = min(dp[i - 1], min(dp[i / 2], dp[i / 3]));
//         }
//         else {
//             if (i % 2 == 0) {
//                 minimum = min(dp[i - 1], dp[i / 2]);
//             }
//             if (i % 3 == 0) {
//                 minimum = min(dp[i - 1], dp[i / 3]);
//             }
//             if (i % 2 != 0 && i % 3 != 0) {
//                 minimum = dp[i - 1];
//             }
//         }
//         dp.pb(minimum + 1);
//     }
//     return dp[n];
// }

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        int dp[n] = {0};
        cout << "Case " << cased << ": " << minsteps(n, dp) << endl;
        cased++;
        // cout << min(1, 3, 4);
    }
}