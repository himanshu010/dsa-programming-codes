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
int solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  string s;
  cin >> s;
  n = s.size();
  vector<bool> alpha1(26, 0);
  for (int i = 0; i < n; ++i) {
    if (alpha1[(int)s[i] - 97] == 0) {
      cnt++;
    }
    alpha1[(int)s[i] - 97] = 1;
  }

  vector<int> alpha(26, 0);

  i = 0;
  j = 0;
  ans = INT_MAX;
  while (j < n) {
    sum = 0;
    alpha[(int)s[j] - 97] += 1;
    for (auto x : alpha) {
      if (x != 0) {
        sum++;
      }
    }

    if (sum == cnt) {
      bool flag = 1;
      while (flag) {
        int cost = 0;
        alpha[(int)s[i] - 97] -= 1;

        if (alpha[(int)s[i] - 97] == 0) {
          alpha[(int)s[i] - 97] += 1;
          flag = 0;
          break;
        }
        i++;
      }

      ans = min(ans, j - i + 1);
    }

    j++;
  }
  return ans;
}
int32_t main() {
  // #ifndef ONLINE_JUDGE
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  // #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  int t;
  cin >> t;
  while (t--) {
    cout << solve(tc) << endl;
    tc++;
  }
}