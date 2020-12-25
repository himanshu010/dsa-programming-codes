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

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> increasing(n, 1);
    vector<int> decreasing(n, 1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (a[j] < a[i] and increasing[i] < increasing[j] + 1)
            {
                increasing[i] = increasing[j] + 1;
            }
        }
    }

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = n - 1; j >= i; --j)
        {
            if (a[j] < a[i] and decreasing[i] < decreasing[j] + 1)
            {
                decreasing[i] = decreasing[j] + 1;
            }
        }
    }

    int maximum = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        maximum = max(maximum, increasing[i] + decreasing[i] - 1);
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