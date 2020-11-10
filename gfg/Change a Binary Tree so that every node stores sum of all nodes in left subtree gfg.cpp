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

class Node {

public:
  int val;
  Node* left;
  Node* right;

  Node(int d) {
    val = d;
    left = right = NULL;
  }


};

int convert(Node* temp) {
  int l, r;
  l = r = 0;

  if (temp->left == NULL and temp->right == NULL) {
    return temp->val;
  }

  if (temp->left) {
    l = convert(temp->left);
  }
  if (temp->right) {
    r = convert(temp->right);
  }
  int initial = temp->val;
  temp->val = l + initial;
  return l + r + initial;
}

void inorder(Node* node)
{
  if (node == NULL)
    return;
  inorder(node->left);
  cout << node->val << " ";
  inorder(node->right);
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);
  convert(root);
  inorder(root);

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