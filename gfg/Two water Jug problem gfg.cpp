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
using namespace std;
int gcd(int n, int m)
{
    if (n == 0)
    {
        return m;
    }

    return gcd(m % n, n);
}
int minSteps(int n, int m, int d)
{
    int a = n, b = 0;
    int steps = 1;
    while (a != d && b != d)
    {
        int temp = min(a, m - b);
        a -= temp;
        b += temp;
        steps++;
        if (a == d or b == d)
        {
            break;
        }

        if (a == 0)
        {
            a = n;
            steps++;
        }
        if (b == m)
        {
            b = 0;
            steps++;
        }
    }
    return steps;
}
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m >> k;

    if (m > n)
    {
        swap(m, n);
    }
    if (k > n)
    {
        cout << -1 << endl;
        return;
    }

    if (k % gcd(n, m) != 0)
    {
        cout << -1 << endl;
        return;
    }
    if (k > max(n, m))
    {
        cout << -1 << endl;
        return;
    }
    cout << min(minSteps(n, m, k), minSteps(m, n, k)) << endl;
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