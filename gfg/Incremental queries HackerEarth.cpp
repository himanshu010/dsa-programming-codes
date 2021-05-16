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
#define PQ priority_queue
using namespace std;

vector<int> tree(5000009);
vector<int> sumTree(5000009);
vector<int> modulusTree(5000009);

void buildTree(vector<int> &a, int s, int e, int index)
{
    if (s == e)
    {
        tree[index] = a[s];
        return;
    }

    int mid = (s + e) / 2;
    buildTree(a, s, mid, 2 * index + 1);
    buildTree(a, mid + 1, e, 2 * index + 2);

    tree[index] = max(tree[2 * index + 1], tree[2 * index + 2]);
}

void buildSumTree(vector<int> &a, int s, int e, int index)
{
    if (s == e)
    {
        sumTree[index] = a[s];
        return;
    }
    int mid = (s + e) / 2;
    buildSumTree(a, s, mid, 2 * index + 1);
    buildSumTree(a, mid + 1, e, 2 * index + 2);
    sumTree[index] = sumTree[2 * index + 1] + sumTree[2 * index + 2];
}

void buildModulusTree(vector<int> &a, int s, int e, int index)
{

    if (s == e)
    {
        if (a[s] % 2 == 0)
        {
            modulusTree[index] = 1;
        }
        else
        {
            modulusTree[index] = 0;
        }
        return;
    }

    int mid = (s + e) / 2;
    buildModulusTree(a, s, mid, 2 * index + 1);
    buildModulusTree(a, mid + 1, e, 2 * index + 2);

    modulusTree[index] = modulusTree[2 * index + 1] + modulusTree[2 * index + 2];
}
int query(int s, int e, int l, int r, int index)
{

    if (l > e)
    {
        return INT_MIN;
    }
    if (r < s)
    {
        return INT_MIN;
    }

    if (l <= s and r >= e)
    {
        return tree[index];
    }
    int mid = (s + e) / 2;
    int left = query(s, mid, l, r, 2 * index + 1);
    int right = query(mid + 1, e, l, r, 2 * index + 2);

    return max(left, right);
}
int querySum(int s, int e, int l, int r, int index)
{

    if (l > e)
    {
        return 0;
    }
    if (r < s)
    {
        return 0;
    }

    if (l <= s and r >= e)
    {
        return sumTree[index];
    }
    int mid = (s + e) / 2;
    int left = querySum(s, mid, l, r, 2 * index + 1);
    int right = querySum(mid + 1, e, l, r, 2 * index + 2);

    return left + right;
}

int queryModulus(int s, int e, int l, int r, int index)
{

    if (l > e)
    {
        return 0;
    }
    if (r < s)
    {
        return 0;
    }

    if (l <= s and r >= e)
    {
        return modulusTree[index];
    }

    int mid = (s + e) / 2;
    int left = queryModulus(s, mid, l, r, 2 * index + 1);
    int right = queryModulus(mid + 1, e, l, r, 2 * index + 2);

    return left + right;
}

void updateTree(int i, int s, int e, int index, int upd)
{
    if (i < s or i > e)
    {
        return;
    }

    if (s == e)
    {
        if (s == i)
        {
            tree[index] = upd;
        }
        return;
    }

    int mid = (s + e) / 2;
    updateTree(i, s, mid, 2 * index + 1, upd);
    updateTree(i, mid + 1, e, 2 * index + 2, upd);
    tree[index] = max(tree[2 * index + 1], tree[2 * index + 2]);
}

void updateSumTree(int i, int s, int e, int index, int upd)
{
    if (i < s or i > e)
    {
        return;
    }
    if (s == e)
    {
        if (s == i)
        {
            sumTree[index] = upd;
        }
        return;
    }
    int mid = (s + e) / 2;
    updateSumTree(i, s, mid, 2 * index + 1, upd);
    updateSumTree(i, mid + 1, e, 2 * index + 2, upd);
    sumTree[index] = sumTree[2 * index + 1] + sumTree[2 * index + 2];
}

void updateModulusTree(int i, int s, int e, int index, int upd)
{
    if (i < s or i > e)
    {
        return;
    }
    if (s == e)
    {
        if (s == i)
        {
            if (upd % 2 == 0)
            {
                modulusTree[index] = 1;
            }
            else
            {
                modulusTree[index] = 0;
            }
        }
        return;
    }
    int mid = (s + e) / 2;
    updateModulusTree(i, s, mid, 2 * index + 1, upd);
    updateModulusTree(i, mid + 1, e, 2 * index + 2, upd);
    modulusTree[index] = modulusTree[2 * index + 1] + modulusTree[2 * index + 2];
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    buildTree(a, 0, n - 1, 0);
    buildSumTree(a, 0, n - 1, 0);
    buildModulusTree(a, 0, n - 1, 0);
    for (int i = 0; i < k; ++i)
    {
        int q, l, r;
        cin >> q >> l >> r;
        l--;
        if (q == 2)
        {
            r--;
            int mx = query(0, n - 1, l, r, 0);
            sum = querySum(0, n - 1, l, r, 0);
            int even = queryModulus(0, n - 1, l, r, 0);
            int total = r - l + 1;
            int odd = total - even;
            ans = 0;
            if (mx & 1)
            {
                sum = sum - even;
                ans = ((mx * total) - sum) / 2;
            }
            else
            {
                sum = sum - odd;
                ans = ((mx * total) - sum) / 2;
            }
            cout << ans << endl;
        }
        else
        {
            updateTree(l, 0, n - 1, 0, r);
            updateSumTree(l, 0, n - 1, 0, r);
            updateModulusTree(l, 0, n - 1, 0, r);
        }
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