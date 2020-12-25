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

void preorder(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }

    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }

    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}

void inorder(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->right->left->left = new Node(11);

    inorder(root);
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