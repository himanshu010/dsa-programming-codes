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
#define R return

using namespace std;

void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 1;
    cin >> n;
    int a[n];
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i + 1] - a[i] <= 2)
        {
            sum++;

            if (i == n - 2)
            {
                v.pb(sum);
            }
        }
        else
        {
            v.pb(sum);

            sum = 1;
            if (i == n - 2)
            {
                v.pb(sum);
            }
        }
    }
    int maximum = -1;
    int minimum = INT_MAX;

    for (auto x : v)
    {
        // cout << x;
        maximum = max(maximum, x);
        minimum = min(minimum, x);
    }
    cout << minimum << " " << maximum << endl;
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}