/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.codes )               |
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
#define PQ priority_queue
using namespace std;

int binary_search(vector<int> a, int s, int e, int k)
{
    if (s >= e)
    {
        if (k = a[s])
        {
            return s;
        }
        return -1;
    }

    int mid = s + ((e - s) / 2);
    if (a[mid] == k)
    {
        return mid;
    }

    if (a[s] <= a[mid])
    {
        if (k < a[mid] and k >= a[s])
        {
            return binary_search(a, s, mid - 1, k);
        }
        return binary_search(a, mid + 1, e, k);
    }
    else
    {
        if (k <= a[e] and k > a[mid])
        {
            return binary_search(a, mid + 1, e, k);
        }
        return binary_search(a, s, mid - 1, k);
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> j;
        cout << binary_search(a, 0, n - 1, j) << endl;
        ;
    }
}
int32_t main()
{
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