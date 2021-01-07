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

int countDistinctSubsequence(string s)
{
    int n = s.size();
    int dp[n + 1];
    int alpha[26];
    memset(alpha, -1, sizeof(alpha));
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 2 * dp[i - 1];
        if (alpha[(int)s[i - 1] - 97] != -1)
        {
            dp[i] -= dp[alpha[(int)s[i - 1] - 97] - 1];
            alpha[(int)s[i - 1] - 97] = i;
        }
        else
        {
            alpha[(int)s[i - 1] - 97] = i;
        }
    }
    return dp[n];
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    string s;
    cin >> s;
    cout << countDistinctSubsequence(s) << endl;
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