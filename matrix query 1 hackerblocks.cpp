#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define max INT_MAX


// void updateRange(int *tree, int ss, int se, int l, int r, int  increment, int index ) {
//     if (l > se || r < ss) {
//         return;
//     }
//     if (ss == se) {
//         tree[index] += increment;
//         // cout << tree[index] << "*******" << endl;
//         return;
//     }
//     int mid = (ss + se) / 2;
//     updateRange(tree, ss, mid, l, r, increment, 2 * index);
//     updateRange(tree, mid + 1, se, l, r, increment, 2 * index + 1);
//     tree[index] = min(tree[2 * index], tree[2 * index + 1]);
//     return;
// }



void buildTree(int a[][4], int s , int e , int tree[][4], int index, int r) {
    //Base Case
    if (s == e) {
        tree[index][0] = a[s][0];
        tree[index][1] = a[s][1];
        tree[index][2] = a[s][2];
        tree[index][3] = a[s][3];
        // cout << endl << index << "---->" << tree[index][0] << tree[index][1] << tree[index][2] << tree[index][3] << endl;
        return;
    }
    //Rec case
    int mid = (s + e) / 2;
    buildTree(a, s, mid, tree, 2 * index, r);
    buildTree(a, mid + 1, e, tree, 2 * index + 1, r);
    tree[index][0] = ((tree[2 * index][0] * tree[2 * index + 1][0]) + (tree[2 * index][1] * tree[2 * index + 1][2])) % r;
    tree[index][1] = ((tree[2 * index][0] * tree[2 * index + 1][1]) + (tree[2 * index][1] * tree[2 * index + 1][3])) % r;
    tree[index][2] = ((tree[2 * index][2] * tree[2 * index + 1][0]) + (tree[2 * index][3] * tree[2 * index + 1][2])) % r;
    tree[index][3] = ((tree[2 * index][2] * tree[2 * index + 1][1]) + (tree[2 * index][3] * tree[2 * index + 1][3])) % r;
    // cout << endl << index << "---->" << tree[index][0] << tree[index][1] << tree[index][2] << tree[index][3] << endl;
    // cout << tree[2 * index][0] << "*" << tree[2 * index + 1][0] << "  +  " << tree[2 * index][1] << "*" << tree[2 * index + 1][2];
    return;

}
vector<int> leftAns, rightAns;
vector <int> queryAns = {1, 0, 0, 1};
vector<int> query(int tree[][4], int ss, int se, int qs, int qe, int index, int r) {
    if (ss >= qs && se <= qe) {
        vector<int> v;
        v.pb(tree[index][0]);
        v.pb(tree[index][1]);
        v.pb(tree[index][2]);
        v.pb(tree[index][3]);
        // cout << endl << index << "---->" << queryAns[0] << queryAns[1] << queryAns[2] << queryAns[3] << endl;
        // cout << "=====" << queryAns[2] << tree[index][1] << ((queryAns[2] * tree[index][1])) << (queryAns[3] * tree[index][3]) << ((queryAns[2] * tree[index][1]) + (queryAns[3] * tree[index][3]));

        int temp0 = queryAns[0];
        int temp1 = queryAns[1];
        int temp2 = queryAns[2];
        int temp3 = queryAns[3];
        queryAns[0] = ((temp0 * tree[index][0]) + (temp1 * tree[index][2])) % r;
        queryAns[1] = ((temp0 * tree[index][1]) + (temp1 * tree[index][3])) % r;
        queryAns[2] = ((temp2 * tree[index][0]) + (temp3 * tree[index][2])) % r;
        queryAns[3] = ((temp2 * tree[index][1]) + (temp3 * tree[index][3])) % r;



        // cout << endl << index << "---->" << tree[index][0] << tree[index][1] << tree[index][2] << tree[index][3] << endl;
        // cout << endl << index << "---->" << queryAns[0] << queryAns[1] << queryAns[2] << queryAns[3] << endl;
        // cout << "=====" << queryAns[2] << tree[index][1] << ((queryAns[2] * tree[index][1])) << (queryAns[3] * tree[index][3]) << ((queryAns[2] * tree[index][1]) + (queryAns[3] * tree[index][3]));
        // cout << endl << endl;
        return v;

    }

    if (qe < ss || qs > se) {
        vector <int> v = {1, 0, 0, 1};
        return v;
    }
    int mid = (ss + se) / 2;
    // cout << index;
    leftAns = query(tree, ss, mid, qs, qe, 2 * index, r);
    rightAns = query(tree, mid + 1, se, qs, qe, 2 * index + 1, r);
    // cout << index << "llll---->" << leftAns[0] << leftAns[1] << leftAns[2] << leftAns[3] << endl;
    // cout << index << "rrrr---->" << rightAns[0] << tree[index][1] << tree[index][2] << tree[index][3] << endl;
    vector<int> v(4);
    // v.pb(1);


    // v[0] = ((leftAns[0] * rightAns[0]) + (leftAns[1] * rightAns[2])) % r;
    // v[1] = ((leftAns[0] * rightAns[1]) + (leftAns[1] * rightAns[3])) % r;
    // v[2] = ((leftAns[2] * rightAns[0]) + (leftAns[3] * rightAns[2])) % r;
    // v[3] = ((leftAns[2] * rightAns[1]) + (leftAns[3] * rightAns[3])) % r;

    return v;
}



// void updateNode(int *tree, int ss, int se, int i, int increment, int index) {
//     if (i > se || i < ss) {
//         return;
//     }
//     if (ss == se) {
//         cout << "index: " << ss << endl;
//         cout << tree[index] << "==>";
//         tree[index] += increment;
//         cout << tree[index] << endl;
//         return;
//     }
//     int mid = (ss + se) / 2;
//     updateNode(tree, ss, mid, i, increment, 2 * index);
//     updateNode(tree, mid + 1, se, i, increment, 2 * index + 1);
// }

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
        int j, r, n, q, k, m, ans = 0, cnt = 0, sum = 0;
        cin >> r >> n >> q;
        int Arr[n][4];
        // int n = sizeof(a) / sizeof(int);
        // int *tree = new int[4 * n + 1];
        int tree[4 * n + 1][4];
        for (int i = 1; i <= (4 * n + 1); ++i)
        {
            tree[i][0] = 1;
            tree[i][1] = 1;
            tree[i][2] = 1;
            tree[i][3] = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            int a, b, c, d;
            cin >> Arr[i][0] >> Arr[i][1] >> Arr[i][2] >> Arr[i][3];
        }

        buildTree(Arr, 0, n - 1, tree, 1, r);
        int one = 1;

        // for (int i = 1; i < 4 * n + 1; ++i)
        // {
        //     cout << one << ")." << endl;
        //     one++;
        //     cout << tree[i][0] << tree[i][1] << endl << tree[i][2] << tree[i][3] << endl << endl;
        // }

        vector<int> v;
        v = query(tree, 0, n - 1, 0, 3, 1, r);
        // cout << endl;
        int ed, et;
        queryAns = {1, 0, 0, 1};
        for (int i = 0; i < q; ++i)
        {
            cin >> ed >> et;
            v = query(tree, 0, n - 1, ed - 1, et - 1, 1, r);
            // cout << "ANSWER";
            cout << queryAns[0] << " " << queryAns[1] << endl << queryAns[2] << " " << queryAns[3] << endl ;
            queryAns = {1, 0, 0, 1};
            cout << endl;

        }

        // cout << endl << "----x----x----" << endl;
        // // cin >> l >> r;
        // int i, increment;
        // cin >> i >> increment;
        // // updateNode(tree, 0, n - 1, 2, 10, 1);
        // // updateNode(tree, 0, n - 1, 3, 15, 1);
        // updateRange(tree, 0, n - 1, 2, 3, 10, 1);
        // cout << "----x----x----" << endl;
        // int no_of_query = q;
        // while (no_of_query--) {

        //     int l, r;
        //     cin >> l >> r;
        //     vector<int> v;
        //     v = query(tree, 0, n - 1, l - 1, r - 1, 1, r);
        //     for (auto x : v) {
        //         cout << x << " ";
        //     }
        //     cout << endl;

        // }
        // cout << "leftist";
        // for (auto x : queryAns) {
        //     cout << x;
        // }





    }
}