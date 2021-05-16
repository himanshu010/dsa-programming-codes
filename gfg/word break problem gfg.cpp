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
#define vvb vector<vector<bool>>
#define um unordered_map
using namespace std;

bool check(string s, vector<string> words)
{
    for (int i = 0; i < words.size(); ++i)
    {
        if (!s.compare(words[i]))
        {
            return true;
        }
    }
    return false;
}
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    string str;
    cin >> str;
    m = str.size();

    vvb dp(m, vb(m, 0));
    for (int i = 0; i < m; ++i)
    {
        if (check(str.substr(i, 1), words))
        {
            dp[i][i] = 1;
        }
    }

    int size = 1;
    while (size < m)
    {
        int s = 0;
        int e = s + size;

        while (e < m)
        {
            // cout << s << ' ' << e << endl;
            if (check(str.substr(s, e - s + 1), words))
            {
                dp[s][e] = 1;
            }
            else
            {
                for (int i = s; i <= e; ++i)
                {
                    if (i == s)
                    {
                        if (dp[i][i] and dp[i + 1][e])
                        {
                            dp[s][e] = 1;
                            continue;
                        }
                    }
                    else if (i == e)
                    {
                        if (dp[i][i] and dp[s][i - 1])
                        {
                            dp[s][e] = 1;
                            continue;
                        }
                    }
                    else
                    {
                        if (dp[s][i] and dp[i + 1][e])
                        {
                            dp[s][e] = 1;
                            continue;
                        }
                    }
                }
            }
            s = s + 1;
            e = e + 1;
        }
        size += 1;
    }
    // cout << "  ";
    // for (int i = 0; i < m; ++i)
    // {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (auto x : dp) {
    //     cout << sum++ << ' ';
    //     for (auto y : x) {
    //         cout << y << ' ';
    //     }
    //     cout << endl;
    // }
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