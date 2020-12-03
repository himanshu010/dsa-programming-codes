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
    int i, j, k, n, m, ans = 0, cnt = 1, sum = 0;
    cin >> n;
    vector<int> dp(n);
    dp[0] = 1;
    cin >> m;
    vector<int> a(m), b(m, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
    }

    while (cnt < n) {
        int minimum = INT_MAX;
        vector<int> temp(m);
        for (int i = 0; i < m; ++i)
        {
            int val = dp[b[i]] * a[i];
            temp[i] = val;
            minimum = min(minimum, val);
        }
        for (int i = 0; i < m; ++i)
        {
            if (temp[i] == minimum) {
                b[i]++;
            }
        }

        dp[cnt] = minimum;
        cnt++;
    }

    cout << dp[n - 1];
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