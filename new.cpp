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
#define PQ priority_queue
using namespace std;

vector<P> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int mn = INT_MAX;

bool isValid(int r, int c, vector<vb> &a, int n, int m)
{
    if (r >= 0 and c >= 0 and r < n and c < m and a[r][c])
    {
        for (auto x : moves)
        {
            int next_r = r + x.F;
            int next_c = c + x.S;
        }
        return true;
    }

    return false;
}

bool checkPath(int r, int c, vector<vb> &a, int n, int m, int len)
{
    if (len > mn)
    {
        return false;
    }

    if (c == m - 1)
    {
        mn = min(mn, len);
        return true;
    }

    for (auto x : moves)
    {
        int next_r = r + x.F;
        int next_c = c + x.S;

        if (isValid(next_r, next_c, a, n, m))
        {
            a[r][c] = 0;
            if (checkPath(next_r, next_c, a, n, m, len + 1))
            {
                return true;
            }
            else
            {
                a[r][c] = 1;
            }
        }
    }
    return false;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<vb> a(n, vb(m));
    vector<vb> b(n, vb(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            bool temp;
            cin >> temp;
            a[i][j] = temp;
            b[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!a[i][j])
            {
                for (auto x : moves)
                {
                    int next_r = i + x.F;
                    int next_c = j + x.S;

                    if (next_r >= 0 and next_c >= 0 and next_r < n and next_c < m)
                    {
                        b[next_r][next_c] = 0;
                    }
                }
            }
        }
    }

    a = b;

    bool flag = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i][0])
        {
            if (checkPath(i, 0, a, n, m, 0))
            {
                flag = 1;
            }
            a = b;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
        return;
    }

    cout << mn << endl;
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