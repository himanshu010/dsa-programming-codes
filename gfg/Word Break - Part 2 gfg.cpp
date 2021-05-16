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

void checkRecursive(vector<string> &a, string s, int n, int m, string op, string ans, int cur)
{

    if (s.size() == op.size())
    {
        if (s.compare(op) == 0)
        {
            cout << '(' << ans.substr(1) << ')';
        }
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if ((op.size() + a[i].size()) <= m and s.substr(cur, a[i].size()).compare(a[i]) == 0)
        {
            checkRecursive(a, s, n, m, op + a[i], ans + " " + a[i], cur + a[i].size());
        }
    }
}

void solve(int tc)
{
    int i, j, k, n, m, cnt = 0, sum = 0;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    string s;
    cin >> s;
    m = s.size();

    checkRecursive(a, s, n, m, "", "", 0);
    cout << endl;
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