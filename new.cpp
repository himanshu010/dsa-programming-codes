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

int maxSum(int a[], int n) {
  int dp[100] = {0};
  dp[0] = a[0] > 0 ? a[0] : 0;
  int max_so_far = dp[0];
  for (int i = 1; i < n; ++i)
  {
    dp[i] = dp[i - 1] + a[i];
    if (dp[i] < 0) {
      dp[i] = 0;
    }
    max_so_far = max(dp[i], max_so_far);
  }
  return max_so_far;
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
    int i, j, k, m, ans = 0, cnt = 0, sum = 0;
    int arr[] = { -3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr) / sizeof(int);
    cout << maxSum(arr, n);
  }
}