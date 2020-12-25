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
bool findTarget(vi a, int n, int sum)
{
    if (sum == 0)
    {
        return true;
    }
    if (n < 0)
    {
        return false;
    }
    if (a[n] > sum)
    {
        return findTarget(a, n - 1, sum);
    }

    return findTarget(a, n - 1, sum) || findTarget(a, n - 1, sum - a[n]);
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
    cin >> sum;
    if (findTarget(a, n - 1, sum))
    {
        cout << "Found Subset of target sum" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
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