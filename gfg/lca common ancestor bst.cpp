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

  int data;
  Node* left;
  Node* right;

  Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};


bool find_path(Node* root, int n, vector<Node*> &path) {

  if (root == NULL) {
    return false;
  }

  path.pb(root);


  if (root->data == n) {
    return true;
  }

  if (root->left and find_path(root->left, n, path)) {
    return true;
  }

  if (root->right and find_path(root->right, n, path)) {
    return true;
  }


  path.pop_back();
  return false;
}



void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  Node* root = new Node(5);
  root->left = new Node(1);
  root->right = new Node(9);
  root->left->right = new Node(4);
  root->right->left = new Node(7);
  // root->right->right = new Node(11);
  // root->left->right->right = new Node(4);
  // root->right->left->left = new Node(8);
  // root->right->right->right = new Node(12);


  vector<Node*> path1, path2;
  find_path(root, 9, path1);
  find_path(root, 4, path2);


  for (auto x : path1) {
    cout << x->data << " ";
  }
  cout << endl;
  for (auto x : path2) {
    cout << x->data << " ";
  }
  cout << endl;


  if (path1.size() <= path2.size()) {
    for (int i = 0; i < path1.size(); i++) {
      if (path1[i]->data != path2[i]->data) {
        cout << path1[i - 1]->data << endl;
        return;
      }

    }
    cout << path1[path1.size() - 1]->data << endl;
    return;
  }
  else {
    for (int i = 0; i < path2.size(); i++) {
      if (path1[i]->data != path2[i]->data) {
        cout << path2[i - 1]->data << endl;
        return;
      }

    }
    cout << path2[path2.size() - 1]->data << endl;
    return;
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