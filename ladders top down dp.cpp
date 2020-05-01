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
#define vb vector<bool>
#define um unordered_map
#define R return

using namespace std;

int ways(int n, int k) {
  int dp[100] = {0};

  if (n == 0) {
    return 1;
  }

  if (dp[n] != 0) {
    return dp[n];
  }
  int sum = 0;
  for (int i = 1; i <= k; ++i)
  {
    if (n - i >= 0) {
      int tways = ways(n - i, k);
      sum = sum + tways;
    }
  }
  return dp[n] = sum;


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
  // int t;cin>>t;while(t--)
  {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    cout << ways(n, k);

  }
}