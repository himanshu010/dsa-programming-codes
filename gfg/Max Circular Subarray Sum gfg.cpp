/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|               ( himanshuaswal.codes )                     |
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

int kadane(vector<int> a)
{
    vector<int> dp(a.size());
    dp[0] = a[0];
    int maximum = INT_MIN;
    for (int i = 1; i < a.size(); ++i)
    {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        maximum = max(dp[i], maximum);
    }
    return maximum;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (n == 1)
    {
        cout << a[0] << endl;
        return;
    }

    int ans1 = kadane(a);
    for (int i = 0; i < n; ++i)
    {
        a[i] *= -1;
    }

    int neg = kadane(a);

    int ans2 = sum + neg;
    if (ans2 == 0)
    {
        ans2 = INT_MIN;
    }
    ans = max(ans1, ans2);
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
    int t;
    cin >> t;
    while (t--)
    {
        solve(tc);
        tc++;
    }
}