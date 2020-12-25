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

bool compare(P a, P b)
{
    if (a.S == b.S)
    {
        return a.F < b.F;
    }
    return a.S < b.S;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<P> a(n);
    for (int i = 0; i < n; ++i)
    {
        int temp1;
        cin >> temp1;
        a[i] = {temp1, 0};
    }
    for (int i = 0; i < n; ++i)
    {
        int temp2;
        cin >> temp2;
        a[i].S = temp2;
    }

    sort(a.begin(), a.end(), compare);

    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i)
    {
        int maximum = INT_MIN;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] <= a[i] and dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    int maximum = INT_MIN;
    for (auto x : dp)
    {
        maximum = max(maximum, x);
    }
    cout << maximum << endl;
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