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
#define R return

using namespace std;

int reset[5000];

void KMPpreprocess(string pattern)
{
    int i = 0, j = -1;
    reset[0] = -1;
    while (i < pattern.size())
    {
        while (j >= 0 && pattern[i] != pattern[j])
        {
            j = reset[j];
        }
        i++;
        j++;
        reset[i] = j;
    }
}
set<P> st;
void check(int l, int r, int n)
{
    for (int i = 0; i <= l; i++)
    {
        for (int j = r; j < n; ++j)
        {
            st.insert({i, j});
        }
    }
}

vector<P> pp;
void KMPsearch(string str, string pattern, int n)
{
    KMPpreprocess(pattern);
    int i = 0;
    int j = 0;
    int sum = INT_MIN;
    while (i < str.size())
    {
        while (j >= 0 and str[i] != pattern[j])
        {
            j = reset[j];
        }
        i++;
        j++;
        if (j == pattern.size())
        {
            int left = i - j;
            int right = i - j + pattern.size() - 1;

            pp.pb({left, right});

            j = reset[j];
        }
    }
}

void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    for (int i = 0; i < 5000; ++i)
    {
        reset[i] = -1;
    }
    string str, pat;
    cin >> str;
    pat = "bear";
    n = str.size();
    KMPsearch(str, pat, n);
    for (auto x : pp)
    {
        check(x.F, x.S, n);
    }

    cout << st.size() << endl;
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
    // int t;cin>>t;while(t--)
    {
        solve();
    }
}