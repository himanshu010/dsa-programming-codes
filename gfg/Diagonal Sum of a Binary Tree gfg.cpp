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

class Node
{
  public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

map<int, vector<int>> mp;
void diagonalSum(Node *temp, int i)
{
    mp[i].push_back(temp->data);
    if (temp->left)
    {
        diagonalSum(temp->left, i - 1);
    }
    if (temp->right)
    {
        diagonalSum(temp->right, i);
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(6);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->right = new Node(7);
    root->right->left->left = new Node(12);
    root->left->right->left = new Node(11);
    root->left->left->right = new Node(10);

    diagonalSum(root, 0);
    for (auto x : mp)
    {
        sum = 0;
        for (auto y : x.second)
        {
            sum += y;
        }
        cout << sum << endl;
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