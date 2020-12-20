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

int longestSubarrayWithSumK(int *a, int n, int k) {
  unordered_map<int, int> mp;

  int prefixSum = 0;
  int length = 0;

  for (int i = 0; i < n; ++i) {
    prefixSum += a[i];

    if (prefixSum == k and length == 0) {
      length = 1;
    }
    if (prefixSum == k) {
      length = max(length, i + 1);
    }

    if (mp.find(prefixSum - k) != mp.end()) {
      length = max(length, i - mp[prefixSum - k]);
    } else {
      mp[prefixSum] = i;
    }
  }
  return length;
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;

  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  cin >> k;

  cout << longestSubarrayWithSumK(a, n, k);
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
    int tc = 1;
    solve(tc);
    tc++;
  }
}