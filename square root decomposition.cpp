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

int query(int *blocks, int *a, int l, int r, int rn)
{
    int ans = 0;
    // Left Part
    while (l < r && l != 0 && l % rn != 0)
    {
        ans += a[l];
        l++;
    }

    // Middle Part
    while (l + rn <= r)
    {
        int block_id = l / rn;
        ans += blocks[block_id];
        l += rn;
    }

    // Right Part
    while (l <= r)
    {
        ans += a[l];
        l++;
    }
    return ans;
}

void update(int index, int rn, int *blocks, int *a, int update)
{
    int block_id = index / rn;
    blocks[block_id] -= a[index];
    blocks[block_id] += update;
}

void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;

    int a[] = {1, 3, 5, 2, 7, 6, 3, 1, 4, 8};
    n = sizeof(a) / sizeof(int);

    int rn = sqrt(n);
    int *blocks = new int[rn + 1]{0};

    int block_id = -1;

    for (int i = 0; i < n; ++i)
    {
        if (i % rn == 0)
        {
            block_id++;
        }
        blocks[block_id] += a[i];
    }

    // Print the blocks array;
    for (int i = 0; i <= rn; ++i)
    {
        cout << blocks[i] << " ";
    }
    cout << endl;

    // Query
    cout << query(blocks, a, 2, 8, rn);

    int x, y;

    // Update
    update(3, rn, blocks, a, 15);
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
        solve();
    }
}