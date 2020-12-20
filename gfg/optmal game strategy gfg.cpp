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

int me = 0, you = 0;

long long gameStrategy(vi a, int s, int e, vvi &dp) {
  if (dp[s][e] != -1) {
    return dp[s][e];
  }

  if (s == e) {
    return a[s];
  }
  if (s == e - 1) {
    return max(a[s], a[e]);
  }
  return dp[s][e] = max((a[s] + min(gameStrategy(a, s + 2, e, dp),
                                    gameStrategy(a, s + 1, e - 1, dp))),
                        (a[e] + min(gameStrategy(a, s + 1, e - 1, dp),
                                    gameStrategy(a, s, e - 2, dp))));
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vvi dp(n + 1, vi(n + 1, -1));
  cout << gameStrategy(a, 0, n - 1, dp);
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