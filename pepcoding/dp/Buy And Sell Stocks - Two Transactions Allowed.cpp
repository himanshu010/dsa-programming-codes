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

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vi pre(n, 0);
    int mn = a[0];
    for (int i = 1; i < n; ++i)
    {
        mn = min(a[i], mn);
        pre[i] = max(pre[i - 1], a[i] - mn);
    }

    vi suff(n, 0);
    int mx = a[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        mx = max(mx, a[i]);
        suff[i] = max(suff[i + 1], mx - a[i]);
    }

    ans = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, pre[i] + suff[i]);
    }
    cout << ans << endl;
}
int32_t main()
{
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