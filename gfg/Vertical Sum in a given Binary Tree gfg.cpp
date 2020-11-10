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

#include<bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map

using namespace std;

map <int, vector<int>> mp;
class Node
{
public:
  int data;
  Node* left;
  Node* right;
  Node(int d) {
    data = d;
    left = right = NULL;
  }
};

void vertical_traversal(Node*temp, int i) {
  mp[i].push_back(temp->data);
  if (temp->left) {
    vertical_traversal(temp->left, i - 1);
  }
  if (temp->right) {
    vertical_traversal(temp->right, i + 1);
  }
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  vector<int> a;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  root->right->left->right = new Node(8);
  root->right->right->right = new Node(9);
  vertical_traversal(root, 0);

  for (auto x : mp) {
    sum = 0;
    for ( auto y : x.second) {
      sum += y;
    }
    a.push_back(sum);
  }

  for (auto x : sum) {
    cout << x << ' ';
  }
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
  int tc = 1;
  // int t;cin>>t;while(t--)
  {
    solve(tc);
    tc++;
  }
}