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
#define PQ priority_queue
using namespace std;

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int x = a[n - 1];
    int y = a[0];
    int mx = INT_MIN, mx1 = INT_MIN;
    for (int i = n - 2; i >= 0; --i)
    {
        mx = max(x * a[i] + x - a[i], mx);
    }
    // cout << mx << endl;

    for (int i = 1; i < n; ++i)
    {
        mx1 = max(y * a[i] + y - a[i], mx1);
    }

    cout << max(mx, mx1) << endl;




}
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    int t; cin >> t; while (t--)
    {
        solve(tc);
        tc++;
    }
}