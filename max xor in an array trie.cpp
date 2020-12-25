/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|               ( himanshuaswal.codes )                     |
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

string decTobin(int n)
{
    string a = "0000000000000000000000000000000000000000000000000000000000000000";
    int i = 63;
    while (n > 0)
    {
        int temp = n & 1;
        if (temp == 1)
        {
            a[i] = '1';
        }
        n = n >> 1;
        i--;
    }
    return a;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    // vector<int> a;
    vector<string> mat(n);
    trie t;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        mat[i] = decTobin(temp);
        t.insert(mat[i]);
    }
    int maximum = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        maximum = max(maximum, stoll(t.query(mat[i]), 0, 2));
    }
    cout << maximum << endl;
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