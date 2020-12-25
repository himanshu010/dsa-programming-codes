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

const int N = 100000000;

vector<int> bit(N, 0);

void update(int i, int increment, int n)
{
    if (i > n)
    {
        return;
    }

    bit[i] += increment;
    i += i & (-i);
    update(i, increment, n);
}

int query(int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += bit[index];
        index -= index & (-index);
    }

    return sum;
}

void solve(int tc)
{
    int i, j, k, n, q, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    int maximum = -1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        maximum = max(maximum, a[i]);
    }
    for (int i = n; i >= 1; --i)
    {
        ans += query(a[i] - 1);
        update(a[i], 1, maximum);
    }

    // cin >> q;
    // cout << bit[2] << "---" << endl;
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
    // int t;cin>>t;while(t--)
    {
        bit.clear();
        bit.resize(N);
        fill(bit.begin(), bit.end(), 0);
        int tc = 1;
        solve(tc);
        tc++;
    }
}