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
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<int> dp(n);
    dp[0] = 1;
    bool flag = 1;
    int maximum = 1;
    int same = 1;
    for (int i = 1; i < n; ++i)
    {
        if (flag and a[i] >= a[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else if (a[i] < a[i - 1] and flag)
        {
            flag = 0;
            dp[i] = dp[i - 1] + 1;
        }
        else if (!flag and a[i] <= a[i - 1])
        {
            if (a[i] == a[i - 1])
            {
                same++;
            }
            else
            {
                same = 1;
            }
            dp[i] = dp[i - 1] + 1;
        }
        else if (!flag and a[i] > a[i - 1])
        {
            flag = 1;
            dp[i] = same + 1;
            same = 1;
        }

        maximum = max(maximum, dp[i]);
    }

    // cout << maximum << endl;
    for (auto x : dp)
    {
        cout << x << ' ';
    }
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