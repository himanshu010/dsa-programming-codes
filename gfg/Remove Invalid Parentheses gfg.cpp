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

int minRemoval(string s, int n)
{

    stack<bool> st;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
        {
            st.push(1);
        }
        if (s[i] == ')')
        {
            if (!st.empty())
            {
                if (st.top())
                {
                    st.pop();
                }
                else
                {
                    st.push(0);
                }
            }
            else
            {
                st.push(0);
            }
        }
    }

    return st.size();
}

set<string> ans;

void afterRemoving(string s, int n, int mn)
{
    if (mn == 0)
    {
        if (minRemoval(s, n) == 0)
        {
            ans.insert(s);
        }
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(' or s[i] == ')')
        {
            string newString = s.substr(0, i) + s.substr(i + 1);
            afterRemoving(newString, n, mn - 1);
        }
    }
}

void solve(int tc)
{
    int i, j, k, n, m, cnt = 0, sum = 0;
    string s;
    cin >> s;

    string op;
    n = s.size();
    int mn = minRemoval(s, n);

    afterRemoving(s, n, mn);

    for (auto x : ans)
    {
        cout << x << endl;
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