/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|               ( himanshuaswal.codes )                     |
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

void solve(int tc) {
  int k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  cin >> k;

  sort(a.begin(), a.end());

  int i = 0;
  int j = i + k - 1;
  int diff = INT_MAX;
  while (j < n) {
    diff = min(diff, a[j] - a[i]);
    i++;
    j++;
  }

  cout << diff << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("inputG.txt", "r", stdin);
  freopen("outputG.txt", "w", stdout);
#endif

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