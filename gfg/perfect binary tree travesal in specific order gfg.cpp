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

class Node
{
  public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

vector<deque<Node *>> mat;
deque<Node *> a, b;

void bfs()
{
    int cnt = 0;
    while (!a.empty())
    {
        Node *temp = a.front();
        // cout << temp->data << " ";
        a.pop_front();
        if (temp->left and temp->right)
        {
            b.pb(temp->left);
            b.pb(temp->right);
        }
    }

    mat.pb(b);
    a = b;
    b.clear();
    if (a.size() != 0)
    {
        bfs();
    }
}
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    root->left->left->left->left = new Node(16);
    root->left->left->left->right = new Node(17);
    root->left->left->right->left = new Node(18);
    root->left->left->right->right = new Node(19);
    root->left->right->left->left = new Node(20);
    root->left->right->left->right = new Node(21);
    root->left->right->right->left = new Node(22);
    root->left->right->right->right = new Node(23);
    root->right->left->left->left = new Node(24);
    root->right->left->left->right = new Node(25);
    root->right->left->right->left = new Node(26);
    root->right->left->right->right = new Node(27);
    root->right->right->left->left = new Node(28);
    root->right->right->left->right = new Node(29);
    root->right->right->right->left = new Node(30);
    root->right->right->right->right = new Node(31);
    a.pb(root);
    mat.pb(a);
    bfs();

    cout << mat.size() << endl;

    // for (auto x : mat) {
    //   int i = 0, j = x.size() - 1;

    //   if (i == j) {
    //     cout << x[i]->data << ' ';
    //   }
    //   else {
    //     while (i < j) {
    //       if (cnt % 2 == 0) {
    //         cout << x[i]->data << ' ';
    //         i++;
    //       }
    //       else {
    //         cout << x[j]->data << ' ';
    //         j--;
    //       }
    //     }
    //   }
    // }

    for (auto x : mat)
    {
        cnt = 0;
        while (!x.empty())
        {
            if (cnt % 2 == 0)
            {
                cout << x.front()->data << ' ';
                x.pop_front();
                cnt++;
            }
            else
            {
                cout << x.back()->data << ' ';
                x.pop_back();
                cnt++;
            }
        }
        cout << endl;
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
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}