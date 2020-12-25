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

int longestSubarrayWithSumZero(int *a, int n)
{
    um<int, int> mp;
    int pre = 0;
    int length = 0;
    for (int i = 0; i < n; ++i)
    {
        pre += a[i];

        if (a[i] == 0 and length == 0)
        {
            length = 1;
        }
        if (pre == 0)
            length = max(length, i + 1);

        if (mp.find(pre) != mp.end())
        {
            length = max(length, i - mp[pre]);
        }
        else
        {
            mp[pre] = i;
            cout << pre << " " << i << endl;
        }
    }

    return length;
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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cout << longestSubarrayWithSumZero(a, n);
    }
}