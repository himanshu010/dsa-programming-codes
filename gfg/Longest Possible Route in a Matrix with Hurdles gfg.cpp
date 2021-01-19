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

vector<P> moves = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool isValid(int r, int c, vvi &a, int n, int m)
{
    if (r >= 0 and c >= 0 and r < n and c < m and a[r][c])
    {
        return true;
    }
    return false;
}

int mx = INT_MIN;

void findMaxPath(int r, int c, int dst_r, int dst_c, vvi &a, int n, int m, int len)
{

    // cout << r << ' ' << c << endl;

    if (r == dst_r and c == dst_c)
    {
        // cout << len << endl;
        mx = max(mx, len);
        return;
    }
    for (auto x : moves)
    {
        int next_r = r + x.F;
        int next_c = c + x.S;

        if (isValid(next_r, next_c, a, n, m))
        {
            a[next_r][next_c] = 0;
            findMaxPath(next_r, next_c, dst_r, dst_c, a, n, m, len + 1);
            a[next_r][next_c] = 1;
        }
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<vector<int>> a(n, vi(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    int src_r, src_c, dst_r, dst_c;
    cin >> src_r >> src_c >> dst_r >> dst_c;

    if (!a[src_r][src_c] and !a[dst_r][dst_c])
    {
        cout << -1 << endl;
        return;
    }

    a[src_r][src_c] = 0;
    findMaxPath(src_r, src_c, dst_r, dst_c, a, n, m, 0);
    cout << mx << endl;
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