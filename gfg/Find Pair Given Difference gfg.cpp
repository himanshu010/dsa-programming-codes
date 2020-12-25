/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|               ( himanshuaswal.codes )                     |
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
bool search(int target, vi a, int s, int e)
{
    if (s == e)
    {
        if (a[s] == target)
        {
            return true;
        }
        return false;
    }
    if (s > e)
    {
        return false;
    }
    int mid = (s + e) / 2;
    if (target == a[mid])
    {
        return true;
    }
    bool ans1 = false, ans2 = false;
    if (a[mid] < target)
    {
        ans1 = search(target, a, mid + 1, e);
    }
    else
    {
        ans2 = search(target, a, s, mid);
    }
    if (ans1 or ans2)
    {
        return true;
    }
    return false;
}
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; ++i)
    {
        if (search(k + a[i], a, i + 1, n - 1))
        {
            cout << 1 << endl;
            return;
        }
    }

    cout << -1 << endl;
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