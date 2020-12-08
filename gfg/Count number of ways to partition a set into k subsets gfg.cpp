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
int total_subsets(int n, int k, vvi &dp) {
    if (dp[n][k] != -1) {
        return dp[n][k];
    }
    if (k > n or n == 0 or k == 0) {
        return 0;
    }

    if (k == 1 or k == n) {
        return 1;
    }

    return dp[n][k] = k * total_subsets(n - 1, k, dp) + total_subsets(n - 1, k - 1, dp);
}
void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
    cout << total_subsets(n, k, dp) << endl;

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