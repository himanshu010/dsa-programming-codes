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

vector<int> parent(100005);

int getSuperParent(int n)
{
    if (n == parent[n])
    {
        return n;
    }

    return parent[n] = getSuperParent(parent[n]);
}

bool compare(pair<P, int> a, pair<P, int> b)
{
    return a.S < b.S;
}
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<pair<P, int>> a(m);
    for (int i = 0; i < m; ++i)
    {
        int l, r, w;
        cin >> l >> r >> w;
        a[i] = {{l, r}, w};
    }
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }
    sort(a.begin(), a.end(), compare);
    vector<P> mst;
    for (auto x : a)
    {
        if (cnt == n)
        {
            break;
        }
        int l = x.F.F;
        int r = x.F.S;
        int parentL = getSuperParent(l);
        int parentR = getSuperParent(r);
        if (parentL != parentR)
        {
            mst.pb({l, r});
            parent[parentL] = parentR;
            cnt++;
        }
    }
    for (auto x : mst)
    {
        cout << x.F << ' ' << x.S << endl;
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