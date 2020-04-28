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
#define um unordered_map
#define R return

using namespace std;

int wine_profit(int wines[], int i, int j, int y, int dp[][100]) {
  if (i > j) {
    return 0;
  }
  if (dp[i][j] != 0) {
    return dp[i][j];
  }
  int left = wines[i] * y + wine_profit(wines, i + 1, j, y + 1, dp);
  int right = wines[j] * y + wine_profit(wines, i, j - 1, y + 1, dp);
  return dp[i][j] = max(left, right);
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
    int p[] = {2, 3, 5, 1, 4};
    int dp[100][100] = {0};

    cout << wine_profit(p, 0, 4, 1, dp) << endl;

    // for (int i = 0; i <= 100; ++i)
    // {
    // for (int j = 0; j <= 100; ++j)
    // {
    //   if (dp[i][j] != 0)
    //     cout << dp[i][j] << " ";
    // }
    // cout << endl;
    // }


  }
}