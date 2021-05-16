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
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = i; j < n - 1 - i; ++j)
        {
            int temp = a[i][j];
            a[i][j] = a[j][n - 1 - i];
            a[j][n - 1 - i] = a[n - 1 - i][n - 1 - j];
            a[n - 1 - i][n - 1 - j] = a[n - 1 - j][i];
            a[n - 1 - j][i] = temp;
        }
    }

    for (auto x : a)
    {
        for (auto y : x)
        {
            cout << y << ' ';
        }
    }
    cout << endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputG.txt", "r", stdin);
    freopen("outputG.txt", "w", stdout);
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