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

pair<int, pair<int, int>> expandString(string s, int l, int r) {
  while (l >= 0 and r < s.size()) {
    if (s[l] == s[r]) {
      l--;
      r++;
    } else {
      break;
    }
  }
  l++;
  r--;
  if (l == r) {
    return {1, {l, r}};
  }
  return {r - l + 1, {l, r}};
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  string s;
  cin >> s;
  int left, right;
  n = s.size();

  i = 0;
  int mx = INT_MIN;
  pair<int, pair<int, int>> val;
  while (i < n) {
    val = expandString(s, i, i);
    if (mx < val.F) {
      mx = val.F;
      left = val.S.F;
      right = val.S.S;
    }
    if (i != n - 1) {
      if (s[i] == s[i + 1]) {
        val = expandString(s, i, i + 1);
        if (mx < val.F) {
          mx = val.F;
          left = val.S.F;
          right = val.S.S;
        }
      }
    }
    i++;
  }
  for (int i = left; i <= right; i++) {
    cout << s[i];
  }
  cout << endl;
}
int32_t main() {
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  int t;
  cin >> t;
  while (t--) {
    solve(tc);
    tc++;
  }
}