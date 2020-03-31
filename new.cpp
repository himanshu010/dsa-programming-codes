#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define max INT_MAX

int lazy[1000] = {0};

void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index) {
    //Never Go down if you have lazy value at the node
    if (lazy[index] != 0) {
        tree[index] += lazy[index];
        // if not a leaf node
        //then lazy value will be passed to children
        if (ss != se) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];

        }
        lazy[index] = 0;
    }
    //out of Bounds
    if (r < ss || l > se) {
        return;
    }
    if (ss >= l && se <= r) {
        tree[index] += inc;
        //Pass the lazy value to the children
        if (ss != se) {
            lazy[2 * index] += inc;
            lazy[2 * index + 1] += inc;
        }

    }
    return;

}


void updateRange(int *tree, int ss, int se, int l, int r, int  increment, int index ) {
    if (l > se || r < ss) {
        return;
    }
    if (ss == se) {
        tree[index] += increment;
        // cout << tree[index] << "*******" << endl;
        return;
    }
    int mid = (ss + se) / 2;
    updateRange(tree, ss, mid, l, r, increment, 2 * index);
    updateRange(tree, mid + 1, se, l, r, increment, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}



void buildTree(int *a, int s , int e , int *tree, int index) {
    //Base Case
    if (s == e) {
        tree[index] = a[s];
        return;
    }
    //Rec case
    int mid = (s + e) / 2;
    buildTree(a, s, mid, tree, 2 * index);
    buildTree(a, mid + 1, e, tree, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;

}

int query(int *tree, int ss, int se, int qs, int qe, int index) {
    if (ss >= qs && se <= qe) {
        return tree[index];
    }

    if (qe < ss || qs > se) {
        return max;
    }
    int mid = (ss + se) / 2;
    int leftAns = query(tree, ss, mid, qs, qe, 2 * index);
    int rightAns = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
    return min(leftAns, rightAns);
}


void updateNode(int *tree, int ss, int se, int i, int increment, int index) {
    if (i > se || i < ss) {
        return;
    }
    if (ss == se) {
        cout << "index: " << ss << endl;
        cout << tree[index] << "==>";
        tree[index] += increment;
        cout << tree[index] << endl;
        return;
    }
    int mid = (ss + se) / 2;
    updateNode(tree, ss, mid, i, increment, 2 * index);
    updateNode(tree, mid + 1, se, i, increment, 2 * index + 1);
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int j, k, m, ans = 0, cnt = 0, sum = 0;
        int a[] = {1, 3, 2, -5, 6, 4};
        int n = sizeof(a) / sizeof(int);
        // int *tree = new int[4 * n + 1];
        int tree[4 * n + 1] = {max};

        buildTree(a, 0, n - 1, tree, 1);
        cout << "tree:" << endl;
        for (int i = 1; i <= 13; ++i)
        {
            cout << tree[i] << " ";
        }
        cout << endl << "----x----x----" << endl;
        // cin >> l >> r;
        // int i, increment;
        // cin >> i >> increment;
        // updateNode(tree, 0, n - 1, 2, 10, 1);
        // updateNode(tree, 0, n - 1, 3, 15, 1);
        // updateRange(tree, 0, n - 1, 2, 3, 10, 1);
        cout << "----x----x----" << endl;

        updateRangeLazy(tree, 0, n - 1, 2, 3, 10, 1);
        int no_of_query = 6;
        while (no_of_query--) {

            int l, r;
            cin >> l >> r;
            cout << query(tree, 0, n - 1, l, r, 1) << endl;

        }






    }
}