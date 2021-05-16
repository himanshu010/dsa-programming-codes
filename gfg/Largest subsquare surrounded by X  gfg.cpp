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
#define PQ priority_queue
using namespace std;

int subsquareSurroundedByX(vector<vector<char>> mat, int n)
{
    vector<vector<P>> a(n, vector<P>(n, {0, 0}));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0)
            {
                if (mat[i][j] == 'X')
                {
                    a[i][j].S = 1;
                }
            }
            else
            {
                if (mat[i][j] == 'X')
                {
                    a[i][j].S = a[i - 1][j].S + 1;
                }
            }
            if (j == 0)
            {
                if (mat[i][j] == 'X')
                {
                    a[i][j].F = 1;
                }
            }
            else
            {
                if (mat[i][j] == 'X')
                {
                    a[i][j].F = a[i][j - 1].F + 1;
                }
            }
        }
    }

    // for (auto x : a) {
    //     for (auto y : x) {
    //         cout << y.F << y.S << ' ';
    //     }
    //     cout << endl;
    // }
    int ans = INT_MIN;

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            int mn = min(a[i][j].F, a[i][j].S);
            if (mn < ans)
            {
                continue;
            }
            for (int k = mn - 1; k >= 0; k--)
            {
                if (i - k >= 0 and j - k >= 0)
                {
                    int left = a[i][j - k].S - 1;
                    int top = a[i - k][j].F - 1;

                    if (left >= k and top >= k)
                    {
                        ans = max(ans, k);
                        break;
                    }
                }
            }
        }
    }
    if (ans == INT_MIN)
    {
        return 0;
    }
    return ans + 1;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<vector<char>> mat(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }
    cout << subsquareSurroundedByX(mat, n) << endl;
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