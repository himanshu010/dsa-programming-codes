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

int getMinDif(vector<int> a, int n, int k)
{
    if (n <= 1)
    {
        return 0;
    }

    sort(a.begin(), a.end());
    int ans = a[n - 1] - a[0];
    vector<int> mn(n), mx(n);
    for (int i = 0; i < n; ++i)
    {
        mn[i] = a[i] - k;
        mx[i] = a[i] + k;
    }

    int i = 0;
    while (i < n and mn[i] < 0)
    {
        i++;
    }

    if (i == n)
    {
        return ans;
    }
    if (i == 0)
        i++;

    for (int j = i; j < n; ++j)
    {
        ans = min(ans, max(mn[n - 1], mx[j - 1]) - min(mx[0], mn[j]));
    }
    return ans;
}
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cin >> k;

    cout << getMinDif(a, n, k);
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