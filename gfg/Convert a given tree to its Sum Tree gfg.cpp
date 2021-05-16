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
        left = right = NULL;
    }
};

int convert_to_sum_tree(Node *temp)
{
    if (temp->left == NULL and temp->right == NULL)
    {
        int val = temp->data;
        temp->data = 0;
        return val;
    }
    int l, r;
    l = r = 0;
    if (temp->left)
    {
        l = convert_to_sum_tree(temp->left);
    }
    if (temp->right)
    {
        r = convert_to_sum_tree(temp->right);
    }

    int initial = temp->data;
    temp->data = l + r;
    return temp->data + initial;
}

void printInorder(Node *Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout << " " << Node->data;
    printInorder(Node->right);
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    convert_to_sum_tree(root);
    printInorder(root);
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