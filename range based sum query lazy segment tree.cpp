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

const int N = 100005;

vector<int> tree(N, 0);
vector<int> lazy(N, 0);

void buildtree(int *a, int start, int end, int index)
{
    if (start == end)
    {
        tree[index] = a[start];
        return;
    }

    int mid = (start + end) / 2;

    buildtree(a, start, mid, 2 * index);
    buildtree(a, mid + 1, end, 2 * index + 1);

    tree[index] = tree[2 * index] + tree[2 * index + 1];
}

void updaterangeLAZY(int node_start, int node_end, int update_start, int update_end, int update_value, int index)
{
    if (lazy[index] != 0)
    {
        cout << (lazy[index] * (node_end - node_start + 1)) << endl;
        tree[index] += (lazy[index] * (node_end - node_start + 1));

        if (node_start != node_end)
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }

        lazy[index] = 0;
    }

    if (update_end < node_start or update_start > node_end)
    {
        return;
    }

    if (update_start <= node_start and update_end >= node_end)
    {
        tree[index] += (update_value * (node_end - node_start + 1));
        if (node_start != node_end)
        {
            lazy[2 * index] += update_value;
            lazy[2 * index + 1] += update_value;
        }
        return;
    }

    int mid = (node_start + node_end) / 2;

    updaterangeLAZY(node_start, mid, update_start, update_end, update_value, 2 * index);
    updaterangeLAZY(mid + 1, node_end, update_start, update_end, update_value, 2 * index + 1);

    tree[index] = tree[2 * index] + tree[2 * index + 1];
}

int queryLazy(int node_start, int node_end, int query_start, int query_end, int index)
{
    if (lazy[index] != 0)
    {
        tree[index] += (lazy[index] * (node_end - node_start + 1));

        if (node_start != node_end)
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }

        lazy[index] = 0;
    }

    if (query_start > node_end or query_end < node_start)
    {
        return 0;
    }

    if (query_start <= node_start and query_end >= node_end)
    {
        return tree[index];
    }

    int mid = (node_start + node_end) / 2;

    int left = queryLazy(node_start, mid, query_start, query_end, 2 * index);
    int right = queryLazy(mid + 1, node_end, query_start, query_end, 2 * index + 1);

    return (left + right);
}

void solve(int tc)
{
    int i, j, k, q, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    buildtree(a, 0, n - 1, 1);

    updaterangeLAZY(0, n - 1, 0, 2, 5, 1);

    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << queryLazy(0, n - 1, l, r, 1) << endl;
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
    // int t;cin>>t;while(t--)
    {
        int tc = 1;
        solve(tc);
        tc++;
    }
}