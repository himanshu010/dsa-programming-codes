/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|                       (himanshu010)                       |
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
#define R return

using namespace std;

int minCoins(int n, int *coins, int T, int dp[]) {
  // Base Case
  if (n == 0) {
    return 0;
  }
  int ans = INT_MAX;
  for (int i = 0; i < T; ++i) {
    if (n - coins[i] >= 0) {
      int subprob = minCoins(n - coins[i], coins, T, dp);
      ans = min(ans, subprob + 1);
    }
  }
  dp[n] = ans;
  return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;cin>>t;while(t--)
  {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    int coins[] = {1, 7, 10};
    n = 15;
    int T = sizeof(coins) / sizeof(int);
    int dp[100] = {0};
    cout << minCoins(n, coins, T, dp);
  }
}