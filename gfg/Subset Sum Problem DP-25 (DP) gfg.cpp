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
void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cin >> sum;
    vector<vector<bool>>dp(n + 1, vector<bool>(sum + 1));
    for (int i = 0; i < n + 1; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < sum + 1; ++i)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            if (a[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            }
        }
    }

    if (dp[n][sum]) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

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