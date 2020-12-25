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

void merge(int arr1[], int arr2[], int n, int m)
{
    int x = n - 1, y = 0;
    while (x >= 0 && y < m)
    {
        if (arr1[x] > arr2[y])
        {
            swap(arr1[x], arr2[y]);
            x--;
            y++;
        }
        else
        {
            x--;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }

    merge(a, b, n, m);
    for (int i = 0; i < m; ++i)
    {
        cout << b[i] << ' ';
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