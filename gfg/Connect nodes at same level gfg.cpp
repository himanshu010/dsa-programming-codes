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
class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node *nextRight;

  Node(int d) {
    data = d;
    left = right = nextRight = NULL;
  }
};

list<Node *> temp1, temp2;
vector<Node *> temp3;

void bfs() {

  for (auto x : temp1) {
    temp3.push_back(x);
  }

  // cout << temp3.size();
  for (int i = 0; i < temp3.size() - 1; ++i) {
    temp3[i]->nextRight = temp3[i + 1];
  }

  temp3[temp3.size() - 1]->nextRight = NULL;

  temp3.clear();

  while (!temp1.empty()) {
    auto cur1 = temp1.begin();
    temp1.pop_front();

    auto cur = *cur1;

    if (cur->left) {
      temp2.push_back(cur->left);
    }
    if (cur->right) {
      temp2.push_back(cur->right);
    }
  }

  temp1 = temp2;
  temp2.clear();
  if (!temp1.empty()) {
    bfs();
  }
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  Node *root = new Node(10);
  root->left = new Node(8);
  root->right = new Node(2);
  root->left->left = new Node(3);
  temp1.push_back(root);

  bfs();
}

int32_t main() {
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