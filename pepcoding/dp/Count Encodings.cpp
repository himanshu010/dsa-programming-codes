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
#define PQ priority_queue
using namespace std;

int solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    string s;
    cin >> s;
    n = s.size();
    vector<int> dp(n);
    if (s[0] == '0')
    {
        return 0;
    }
    dp[0] = 1;

    if (n > 1)
    {
        if (s[1] == '0')
        {
            if (s[0] > 2)
            {
                return 0;
            }
            dp[1] = 1;
        }
        else
        {
            if (s[0] == '1' or (s[0] == '2' and s[1] <= '6'))
            {
                dp[1] = 2;
            }
            else
            {
                dp[1] = 1;
            }
        }
    }

    for (int i = 2; i < n; ++i)
    {
        if (s[i] == '0')
        {
            if (s[i - 1] > 2 or s[i - 1] == 0)
            {
                return 0;
            }
            dp[i] = dp[i - 2];
        }
        else
        {
            dp[i] = dp[i - 1];
            if (s[i - 1] == '1' or (s[i - 1] == '2' and s[i] <= '6'))
            {
                dp[i] += dp[i - 2];
            }
        }
    }

    return dp[n - 1];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        cout << solve(tc);
        tc++;
    }
}