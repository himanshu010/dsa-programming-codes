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
// #define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define R return

using namespace std;

struct point
{
    int x, y;
    bool operator<(point &P)
    {
        if (P.x == x)
            return y < P.y;
        else
            return x < P.x;
    }

    bool operator==(point &P)
    {
        return (x == P.x && y == P.y);
    }
};

bool cw(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool ccw(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool collinear(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
}

void convex_hull(vector<point> &p)
{
    if (p.size() <= 2)
        return;

    sort(p.begin(), p.end());

    // p[0] is p1, p[n-1] is p2

    int i, n = p.size();
    point p1 = p[0], p2 = p[n - 1];

    vector<point> up, down;
    up.pb(p1);
    down.pb(p1);

    // p1 is bottom left and p2 in top right

    for (int i = 1; i < n; ++i)
    {
        // Now i have to check that my point is in upper half or lower half

        if (i == n - 1 || !ccw(p1, p[i], p2))
        {
            // It is in upper half

            while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i]))
            {
                up.pop_back();
            }
            up.pb(p[i]);
        }
        if (i == n - 1 || !cw(p1, p[i], p2))
        {
            // p[i] is in the lower half

            while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i]))
            {
                down.pop_back();
            }
            down.pb(p[i]);
        }
    }
    // up and down vector contains all point includint the points p1 and p2
    // repeatedly
    p.clear();
    for (int i = 0; i < up.size(); ++i)
    {
        p.pb(up[i]);
    }
    for (int i = 0; i < down.size(); ++i)
    {
        p.pb(down[i]);
    }

    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
}

void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].x >> p[i].y;
    }

    map<pair<int, int>, int> mp;

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        point temp;
        cin >> temp.x >> temp.y;
        mp[{temp.x, temp.y}]++;
        p.pb(temp);
    }
    convex_hull(p);

    // Now p contains all the point of convex hull
    for (auto x : p)
    {
        // cout << x.x << " " << x.y << '\n';
        if (mp.count({x.x, x.y}))
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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
    // int t;cin>>t;while(t--)
    {
        solve();
    }
}