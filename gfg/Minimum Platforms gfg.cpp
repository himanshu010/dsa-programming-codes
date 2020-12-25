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

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> arr(n), dep(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> dep[i];
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platform = 1;
    int maximum = 1;
    i = 1;
    j = 0;

    while (i < n and j < n)
    {
        if (arr[i] <= dep[j])
        {
            platform++;
            i++;
        }
        else
        {
            platform--;
            j++;
        }
        maximum = max(maximum, platform);
    }
    cout << maximum << endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputG.txt", "r", stdin);
    freopen("outputG.txt", "w", stdout);
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