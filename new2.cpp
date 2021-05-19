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

bool CanPlaceAtThisGap(int *a, int gap, int cows, int a_size)
{
    int last_pos = a[0];
    int cnt = 1;
    for (int i = 0; i < a_size; ++i)
    {
        if ((a[i] - last_pos) >= gap)
        {
            last_pos = a[i];
            cnt++;
            if (cnt == cows)
            {
                return true;
            }
        }
    }

    return false;
}

int ma
{
    int ans;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (CanPlaceAtThisGap(a, mid, cows, a_size))
        {
            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
    }

    return ans;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    int a[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    cout << searching_max_gap(a, 0, a[n - 1], m, n) << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int tc = 1;
        solve(tc);
        tc++;
    }
}