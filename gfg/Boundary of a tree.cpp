/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|               ( himanshuaswal.codes )                     |
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

void print_left(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left)
    {
        cout << root->data << " ";
        print_left(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        print_left(root->right);
    }
}

void print_right(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->right)
    {
        print_right(root->right);
        cout << root->data << " ";
    }

    else if (root->left)
    {
        print_right(root->left);
        cout << root->data << " ";
    }
}

void print_leaf(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL and root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    if (root->left)
    {
        print_leaf(root->left);
    }
    if (root->right)
    {
        print_leaf(root->right);
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);
    cout << root->data << " ";
    print_left(root->left);
    print_leaf(root);
    print_right(root->right);
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