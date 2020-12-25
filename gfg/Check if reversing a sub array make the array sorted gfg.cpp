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

// _________________________________________________________
// |Three parts of array :-                                 |
// |                                                        |
// |a ............. b | c ............ d | e ............. f|
// |____INCREASING___ | ___DECREASING___ | ____INCREASING___|
// |________________________________________________________|
//
// And,
// b < d
// c < e

bool checkRev(vector<int> a, int n)
{
    int i = 1;
    bool first_Part = 0;
    int maxFirst = INT_MIN;

    while (a[i] > a[i - 1] and i < n)
    {
        maxFirst = a[i];
        i++;
    }

    if (i == n)
    {
        return 1;
    }

    int maxSec = a[i];
    int minSec = INT_MAX;
    while (a[i] < a[i - 1] and i < n)
    {
        minSec = a[i];
        i++;
    }

    // b < d
    if (minSec < maxFirst)
    {
        return 0;
    }
    if (i == n)
    {
        return 1;
    }

    // c < e
    if (a[i] < maxSec)
    {
        return 0;
    }
    while (a[i] > a[i - 1] and i < n)
    {
        i++;
    }
    if (i == n)
    {
        return 1;
    }
    return 0;
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

    cout << checkRev(a, n) << endl;
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