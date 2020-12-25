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
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    string s;
    cin >> s;
    n = s.size();
    cin >> k;
    i = 0;
    j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            cnt++;
        }
        i++;
        j--;
    }

    if (cnt > k)
    {
        cout << -1 << endl;
        return;
    }
    i = 0;
    j = n - 1;
    while (k > cnt)
    {
        if (s[i] != s[j])
        {
            cnt--;
        }
        if (k - 2 < cnt)
        {
            break;
        }
        if (s[i] == '9')
        {
            k++;
        }
        if (s[j] == '9')
        {
            k++;
        }
        s[i] = '9';
        s[j] = '9';

        i++;
        j--;
        k -= 2;
    }

    i = 0;
    j = n - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            s[i] = max(s[i], s[j]);
            s[j] = s[i];
            k--;
        }
        i++;
        j--;
    }

    if (k > 0)
    {
        if (n & 1)
        {
            s[n / 2] = '9';
        }
    }
    cout << s << endl;
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