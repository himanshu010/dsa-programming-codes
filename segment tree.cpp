#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define max INT_MAX

void buildTree(int *a, int s, int e, int *tree, int index)
{
    // BASE CASE
    if (s == e)
    {
        tree[index] = a[s];
        return;
    }
    // REC CASE
    int mid = (s + e) / 2;
    buildTree(a, s, mid, tree, 2 * index);
    buildTree(a, mid + 1, e, tree, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

int query(int *tree, int ss, int se, int qs, int qe, int index)
{
    if (ss >= qs && se <= qe)
    {
        return tree[index];
    }

    if (qe < ss || qs > se)
    {
        return max;
    }
    int mid = (ss + se) / 2;
    int leftAns = query(tree, ss, mid, qs, qe, 2 * index);
    int rightAns = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
    return min(leftAns, rightAns);
}

void updateNode(int *tree, int ss, int se, int i, int update, int index)
{
    if (i > se || i < ss)
    {
        return;
    }
    if (ss == se)
    {
        // COUT UPDATE INFORMATION-1
        cout << "index: " << ss << endl;
        cout << tree[index] << "==>";

        tree[index] += update;

        // COUT UPDATE INFORMATION-2
        cout << tree[index] << endl;

        return;
    }
    int mid = (ss + se) / 2;
    updateNode(tree, ss, mid, i, update, 2 * index);
    updateNode(tree, mid + 1, se, i, update, 2 * index + 1);
}

void updateRange(int *tree, int ss, int se, int l, int r, int update, int index)
{
    if (l > se || r < ss)
    {
        return;
    }
    if (ss == se)
    {
        // COUT UPDATE INFORMATION-1
        cout << "index: " << ss << endl;
        cout << tree[index] << "==>";

        tree[index] += update;

        // COUT UPDATE INFORMATION-2
        cout << tree[index] << endl;

        return;
    }
    int mid = (ss + se) / 2;
    updateRange(tree, ss, mid, l, r, update, 2 * index);
    updateRange(tree, mid + 1, se, l, r, update, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
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
        int j, k, m, ans = 0, cnt = 0, sum = 0, update, indexToUpdate, left, right, no_of_query, queryLeft, queryRight;

        int n;
        cin >> n;
        int a[n];

        // ARRAY HAVE ZERO BASED INDEXING
        // TREE HAVE ONE BASED INDEXING
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        // INITIALISING TREE WITH ZERO
        int tree[4 * n + 1] = {0};

        // BUILDTREE(ARRAY, START, END, TREE, TREE-STARTING-INDEX)
        buildTree(a, 0, n - 1, tree, 1);

        // COUT TREE
        // for (int i = 1; i <= (4 * n + 1); ++i)
        // {
        //     cout << tree[i] << " ";
        // }
        // cout<<endl;

        // UPDATE TREE NODE
        {
            // cin >> indexToUpdate >> update;

            // UPDATENODE(TREE, ARRAY-STARTING, ARRAY-ENDING, INDEX-WHERE-UPDATE,
            // UPDATE, TREE-STARTING-INDEX)
            // updateNode(tree, 0, n - 1, indexToUpdate, update, 1);
        }

        // UPDATE TREE RANGE
        {
            // cin >> left >> right >> update;

            // UPDATERANGE(TREE, TREE-START, TREE-END, RANGE-START, RANGE-END,
            // UPDATE, TREE-STARTING-INDEX)
            // updateRange(tree, 0, n - 1, left, right, update, 1);
        }

        // QUERY
        {
            cin >> no_of_query;
            while (no_of_query--)
            {
                cin >> queryLeft >> queryRight;

                // QUERY(TREE, ARRAY-START, ARRAY-END, QUERY-LEFT, QUERY-RIGHT,
                // TREE-STARTING-INDEX)
                cout << query(tree, 0, n - 1, queryLeft, queryRight, 1) << endl;
            }
        }
    }
}