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

class Node
{
public:
  char data;
  bool terminal;
  int cnt;
  unordered_map<char, Node*> mp;
  Node(char d) {
    data = d;
    terminal = false;
    cnt = 0;
  }

};


void insert(Node* root, string s) {
  Node* temp = root;
  temp->cnt += 1;
  for (int i = 0; i < s.size(); ++i)
  {
    if (temp->mp.count(s[i])) {
      temp = temp->mp[s[i]];
      temp->cnt += 1;
    }
    else {
      Node* newer = new Node(s[i]);
      temp->mp[s[i]] = newer;
      temp = newer;
      temp->cnt += 1;
    }

  }

  temp->terminal = true;
}

string tell(Node* root, string s) {
  string op;
  Node* temp = root;
  for (int i = 0; i < s.size(); ++i)
  {
    if (temp->cnt <= 1) {
      if (temp->data != '$')
        op = op + temp->data;
      return op;
    }
    {
      if (temp->data != '$')
        op = op + temp->data;
      temp = temp->mp[s[i]];
    }
  }
  if (temp->cnt <= 1) {
    op = op + temp->data;
    return op;
  }

  return "-1";
}





void solve(int tc) {
  Node* root = new Node('$');
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; ++i)
  {
    cin >> s[i];
    insert(root, s[i]);
  }

  for (int i = 0; i < n; ++i)
  {
    cout << tell(root, s[i]) << endl;
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