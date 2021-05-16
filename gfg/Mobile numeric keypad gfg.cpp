/*
*-----------------------------------------------------------*
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.com )                 |
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

vector<vector<char>> keys = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'}};
vector<vector<int>> canPress = {{0, 8},          {1, 2, 4},    {1, 2, 3, 5}, {2, 3, 6},       {1, 4, 5, 7},
                                {2, 4, 5, 6, 8}, {3, 5, 6, 9}, {4, 7, 8},    {5, 7, 8, 9, 0}, {6, 9, 8}};

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<vector<int>> dp(2, vector<int>(10));

    for (int i = 0; i < 10; ++i)
    {
        dp[0][i] = 1;
    }
    cnt = 2;
    while (cnt <= n)
    {
        for (int j = 0; j < 10; ++j)
        {
            sum = 0;
            for (int i = 0; i < canPress[j].size(); ++i)
            {
                sum += dp[0][canPress[j][i]];
            }
            dp[1][j] = sum;
        }
        dp[0] = dp[1];
        cnt++;
    }
    for (int i = 0; i < 10; ++i)
    {
        ans += dp[1][i];
    }
    cout << ans << endl;
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