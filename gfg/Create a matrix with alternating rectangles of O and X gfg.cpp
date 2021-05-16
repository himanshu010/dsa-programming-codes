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

vector<P> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         a[i][j] = 'X';
    //     }
    // }
    int sr, er, sc, ec;
    sr = 0;
    er = n - 1;
    sc = 0;
    ec = m - 1;
    i = 0;
    j = 0;
    P cur_dir = dir[0];
    while (sum < n * m)
    {
        if (j == ec and cur_dir == dir[0])
        {
            cur_dir = dir[1];
        }
        if (i == er and cur_dir == dir[1])
        {
            cur_dir = dir[2];
        }
        if (j == sc and cur_dir == dir[2])
        {
            cur_dir = dir[3];
        }
        if (i == sr and cur_dir == dir[3])
        {
            cnt += 1;
            cur_dir = dir[0];
            sr++;
            er--;
            sc++;
            ec--;
            i += 1;
            j += 1;
        }

        if (cnt % 2 == 0)
        {
            a[i][j] = 'X';
        }
        else
        {
            a[i][j] = 'O';
        }

        i += cur_dir.F;
        j += cur_dir.S;
        sum += 1;
    }

    for (auto x : a)
    {
        for (char y : x)
        {
            cout << y << ' ';
        }
        cout << endl;
    }
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