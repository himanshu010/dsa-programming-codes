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

int row[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int col[] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool check(int I, int J, vector<vector<char>> &a, string s, int index, int gr, int gc)
{
    int n = s.size();

    for (int k = 0; k < 8; ++k)
    {
        int z;
        int i = I;
        int j = J;
        for (z = 1; z < n; ++z)
        {
            if (i + row[k] < 0 || i + row[k] >= gr || j + col[k] < 0 || j + col[k] >= gc)
            {
                break;
            }
            if (s[z] != a[i + row[k]][j + col[k]])
            {
                break;
            }
            i += row[k];
            j += col[k];
        }
        if (z == n)
        {
            return true;
        }
    }
    return false;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    bool flag = 0;
    vector<vector<char>> a(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == s[0])
            {
                if (check(i, j, a, s, 0, n, m))
                {
                    flag = 1;
                    cout << i << ' ' << j << ',' << ' ';
                }
            }
        }
    }
    if (!flag)
    {
        cout << -1;
    }

    cout << endl;
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