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

unordered_set<string> ans;
void expandPalindrome(int i, int j, string &a) {
  int n = a.size();
  string op;
  op += a[i];
  if (i != j) {
    op += a[j];
    if (a[i] != a[j]) {
      return;
    }
  }
  ans.insert(op);


  while (i - 1 >= 0 and j + 1 < n) {
    if (a[i - 1] == a[j + 1]) {
      string temp;
      temp += a[i - 1];
      temp += op;
      temp += a[j + 1];
      op = temp;
      temp = "";
      ans.insert(op);
      i--;
      j++;
    }
    else {
      return;
    }
  }
}

void solve(int tc) {
  int i, j, k, n, m, cnt = 0, sum = 0;
  string s;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n - 1; ++i)
  {
    expandPalindrome(i, i, s);
    expandPalindrome(i, i + 1, s);
  }
  expandPalindrome(n - 1, n - 1, s);

  cout << ans.size() << endl;
  ans.clear();


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
  int t; cin >> t; while (t--)
  {
    solve(tc);
    tc++;
  }
}