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

vector<vector<int>> tree(N);

int query(int ns, int ne, int qs, int qe, int k, int index)
{
    vector<int> empty;

    if (ne < qs or ns > qe)
    {
        return 0;
    }

    if (qs <= ns and qe >= ne)
    {
        auto it = lower_bound(tree[index].begin(), tree[index].end(), k);
        int lb = it - tree[index].begin();

        int ans = tree[index].size() - lb;
        return ans;
    }

    int mid = (ns + ne) / 2;

    int left_ans = query(ns, mid, qs, qe, k, 2 * index);
    int right_ans = query(mid + 1, ne, qs, qe, k, 2 * index + 1);

    return left_ans + right_ans;
}

vector<int> buildtree(vector<int> a, int s, int e, int index)
{
    if (s == e)
    {
        tree[index].pb(a[s]);
        return tree[index];
    }

    int mid = (s + e) / 2;

    vector<int> left_node = buildtree(a, s, mid, 2 * index);
    vector<int> right_node = buildtree(a, mid + 1, e, 2 * index + 1);

    vector<int> final_node;
    int i = 0, j = 0;

    while (i < left_node.size() and j < right_node.size())
    {
        if (left_node[i] < right_node[j])
        {
            final_node.pb(left_node[i]);
            i++;
        }
        else
        {
            final_node.pb(right_node[j]);
            j++;
        }
    }

    while (i < left_node.size())
    {
        final_node.pb(left_node[i]);
        i++;
    }
    while (j < right_node.size())
    {
        final_node.pb(right_node[j]);
        j++;
    }

    tree[index] = final_node;

    return final_node;
}

void solve(int tc)
{
    int i, j, k, n, m, q, ans = 0, cnt = 0, sum = 0;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    buildtree(a, 0, n - 1, 1);

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r, k;
        cin >> l >> r >> k;
        ans = query(0, n - 1, l, r, k, 1);
        cout << ans << endl;
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