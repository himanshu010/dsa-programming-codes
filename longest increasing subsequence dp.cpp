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

int lis(int *a, int n) {

  int dp[100];
  for (int i = 0; i <= 100; ++i) {
    dp[i] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    int maximum = 1;
    for (int j = 1; j < i; ++j) {
      if (a[j] <= a[i]) {

        int temp = dp[j] + 1;
        // cout << temp << "--" << endl;
        maximum = max(maximum, temp);
      }
    }
    dp[i] = maximum;
  }
  int ans = 1;
  for (auto x : dp) {
    cout << x << " ";
    ans = max(ans, x);
  }
  cout << endl;
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
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    cout << lis(a, n);
  }
}