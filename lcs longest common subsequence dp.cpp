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

int lcs(char X[], char Y[]) {
  int m = strlen(X);
  int n = strlen(Y);

  int dp[100][100];

  for (int i = 0; i <= m; ++i) {
    dp[i][0] = 0;
    // cout << i << " " << dp[i][0] << endl;
  }
  for (int j = 0; j <= n; ++j) {
    dp[0][j] = 0;
  }

  // for (int i = 0; i <= m; ++i)
  // {
  //   for (int j = 0; j <= n; ++j)
  //   {
  //     cout << dp[i][j]<<" ";
  //   }
  //   cout << endl;
  // }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      int q = 0;
      if (X[i - 1] == Y[j - 1]) {
        q = 1 + dp[i - 1][j - 1];
      } else {
        q = max(dp[i - 1][j], dp[i][j - 1]);
      }
      dp[i][j] = q;
    }
  }

  // for (int i = 0; i <= m; ++i)
  // {
  //   for (int j = 0; j <= n; ++j)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return dp[m][n];
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
    int i, j, k, n, m, ans, cnt = 0, sum = 0;

    char str1[1010], str2[1010];
    cin >> str1 >> str2;
    ans = lcs(str1, str2);
    cout << ans;
  }
}