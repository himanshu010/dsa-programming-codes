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
    int i, j, k, n, m, ans = 0, cnt = 0;
    double sum = 0;
    cin >> n;
    int x, y;
    cin >> x >> y;
    int steps;
    cin >> steps;
    vector<vector<double>>dp1(n, vector<double>(n, 0));
    vector<vector<double>>dp2(n, vector<double>(n, 0));
    dp1[x][y] = 1;

    while (steps > 0) {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dp1[i][j] != 0) {
                    double value = dp1[i][j];
                    if (j - 2 >= 0 and i - 1 >= 0) {
                        dp2[i - 1][j - 2] += value / 8;
                    }
                    if (j - 2 >= 0 and i + 1 < n) {
                        dp2[i + 1][j - 2] += value / 8;
                    }
                    if (i + 2 < n and j - 1 >= 0) {
                        dp2[i + 2][j - 1] += value / 8;
                    }
                    if (i + 2 < n and j + 1 < n) {
                        dp2[i + 2][j + 1] += value / 8;
                    }
                    if (j + 2 < n and i + 1 < n) {
                        dp2[i + 1][j + 2] += value / 8;
                    }
                    if (j + 2 < n and i - 1 >= 0) {
                        dp2[i - 1][j + 2] += value / 8;
                    }
                    if (i - 2 >= 0 and j + 1 < n) {
                        dp2[i - 2][j + 1] += value / 8;
                    }
                    if (i - 2 >= 0 and j - 1 >= 0) {
                        dp2[i - 2][j - 1] += value / 8;
                    }
                }
            }
        }

        dp1 = dp2;
        dp2.clear();
        dp2.resize(n);
        for (int i = 0; i < n; ++i)
        {
            dp2[i].resize(n, 0);
        }
        steps--;
    }

    for (auto x : dp1) {
        for (auto y : x) {
            sum += y;
        }
    }
    cout << sum;


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