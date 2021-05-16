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

string minWindowSubstring(string str, string pat)
{
    int len1 = str.size();
    int len2 = pat.size();

    if (len1 < len2)
    {
        return "No Window";
    }

    int hash_str[256] = {0};
    int hash_pat[256] = {0};

    for (int i = 0; i < len2; ++i)
    {
        hash_pat[pat[i]] += 1;
    }

    int start = 0, start_index = -1, min_len = INT_MAX;

    int count = 0;

    for (int j = 0; j < len1; ++j)
    {
        hash_str[str[j]] += 1;
        if (hash_pat[str[j]] != 0 and hash_str[str[j]] <= hash_pat[str[j]])
        {
            count += 1;
        }

        if (count == len2)
        {
            while (hash_str[str[start]] > hash_pat[str[start]] or hash_pat[str[start]] == 0)
            {
                if (hash_str[str[start]] > hash_pat[str[start]])
                {
                    hash_str[str[start]] -= 1;
                }
                start += 1;
            }

            int len_window = j - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }

    if (start_index == -1)
    {
        return "No Window";
    }

    return str.substr(start_index, min_len);
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    string s1, s2;
    cin >> s1 >> s2;

    cout << minWindowSubstring(s1, s2);
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
        int tc = 1;
        solve(tc);
        tc++;
    }
}