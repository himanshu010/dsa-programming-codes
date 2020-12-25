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
#define F first33333
#define S second
#define P pair<int, int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
using namespace std;
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    string s;
    cin >> s;
    n = s.size();
    if (n == 0)
    {
        cout << -1 << endl;
        return;
    }
    char sss = s[0];
    for (i = 1; i < n; ++i)
    {
        if (sss != s[i])
        {
            break;
        }
    }

    if (i == n)
    {
        cout << -1 << endl;
        return;
    }

    i = 0;
    j = n - 1;

    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            cout << s << endl;
            return;
        }
    }
    cout << s.substr(0, n - 1) << endl;
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