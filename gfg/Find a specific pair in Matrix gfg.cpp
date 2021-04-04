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

bool isValid(int r, int c, int n)
{
    return (r < n and r >= 0 and c < n and c >= 0);
}

int findSpecificPair(vvi a, int n)
{
    vvi dp(n, vi(n));
    dp[n - 1][n - 1] = a[n - 1][n - 1];

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            int bottom = INT_MIN, right = INT_MIN, diagonal = INT_MIN;
            if (isValid(i + 1, j + 1, n))
            {
                bottom = dp[i + 1][j];
                right = dp[i][j + 1];
                diagonal = dp[i + 1][j + 1];
            }
            else if (isValid(i + 1, j, n))
            {
                bottom = dp[i + 1][j];
            }
            else if (isValid(i, j + 1, n))
            {
                right = dp[i][j + 1];
            }

            dp[i][j] = max(max(right, max(bottom, diagonal)), a[i][j]);
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            int mx = dp[i + 1][j + 1];
            ans = max(ans, mx - a[i][j]);
        }
    }
    return ans;
}

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
    cout << findSpecificPair(a, n) << endl;
}

int32_t main()
{
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