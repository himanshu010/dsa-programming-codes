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
#define PQ priority_queue
using namespace std;

int ans = INT_MAX;

bool check(int s, vi &a, int k, int n, int t)
{
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        if (cnt > k)
        {
            return false;
        }

        if (sum + (a[i] * t) <= s)
        {
            sum += (a[i] * t);
        }
        else
        {
            cnt += 1;
            if ((a[i] * t) > s)
            {
                return false;
            }
            else
            {
                sum = (a[i] * t);
            }
        }
    }
    if (cnt > k)
    {
        return false;
    }
    return true;
}

void binarySearch(int s, int e, vi &a, int k, int n, int t)
{

    if (s > e)
    {
        return;
    }

    if (s == e)
    {
        if (check(s, a, k, n, t))
        {
            ans = min(ans, s);
        }
        return;
    }

    int mid = (s + e) / 2;

    if (check(mid, a, k, n, t))
    {
        ans = min(ans, mid);
        binarySearch(s, mid, a, k, n, t);
    }
    else
    {
        binarySearch(mid + 1, e, a, k, n, t);
    }
}

void solve(int tc)
{
    int i, j, k, n, m, t, mn = INT_MAX, cnt = 0, sum = 0;
    cin >> k >> t >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        mn = min(a[i], mn);
    }

    binarySearch(mn * t, sum * t, a, k, n, t);
    cout << ans << endl;
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

// Input type
// 4 5 6
// 10 7 8 12 6 8