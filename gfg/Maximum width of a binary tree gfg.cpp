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
vector<Node *> q1, q2;
int maximum = 1;

void width()
{
    while (!q1.empty())
    {
        Node *f = q1[q1.size() - 1];
        q1.pop_back();
        if (f->left)
        {
            q2.push_back(f->left);
        }

        if (f->right)
        {
            q2.push_back(f->right);
        }
    }

    int wid = q2.size();
    maximum = max(maximum, wid);

    q1 = q2;
    q2.clear();

    if (!q1.empty())
    {
        width();
    }
}

void solve(int tc)
{
    int i, j, k, n, m, cnt = 0, sum = 0;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);

    q1.push_back(root);
    width();
    cout << maximum << endl;
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