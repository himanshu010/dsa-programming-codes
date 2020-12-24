/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|     ( website: himanshu010.github.io/Portfolio_website )  |
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

vector<string> tree(100005);
set<char>temp;

string query(int index, int s, int e, int l, int r) {
  if (l <= s and r >= e) {
    return tree[index];
  }
  if (r<s or l>e) {
    return "";
  }
  int mid = (s + e) / 2;
  string left = query(2 * index + 1, s, mid, l, r);
  string right = query(2 * index + 2, mid + 1, e, l, r);

  temp.clear();
  for (auto x : left) {
    temp.insert(x);
  }
  for (auto y : right) {
    temp.insert(y);
  }

  string ans;
  for (auto x : temp) {
    ans += x;
  }
  return ans;
}

string create(string &a, int s, int e, int index) {
  if (s == e) {
    tree[index] += a[s];
    return tree[index];
  }

  int mid = (s + e) / 2;
  string left = create(a, s, mid, 2 * index + 1);
  string right = create(a, mid + 1, e, 2 * index + 2);
  temp.clear();
  for (auto x : left) {
    temp.insert(x);
  }
  for (auto y : right) {
    temp.insert(y);
  }

  string ans;
  for (auto x : temp) {
    ans += x;
  }
  return tree[index] = ans;
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  string s;
  cin >> s;
  n = s.size();
  create(s, 0, n - 1, 0);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << query(0, 0, n - 1, l - 1, r - 1).size() << ' ';
  }
}
int32_t main()
{
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  int t; cin >> t; while (t--)
  {
    solve(tc);
    tc++;
  }
}