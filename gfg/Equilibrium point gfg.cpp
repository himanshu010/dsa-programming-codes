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
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (a.size() == 1) {
    cout << 1 << endl;
    return;
  }

  vi b(n), c(n);
  b[0] = a[0];
  c[n - 1] = a[n - 1];

  for (int i = 1; i < n; ++i) {
    b[i] = b[i - 1] + a[i];
  }

  for (int i = n - 2; i >= 0; --i) {
    c[i] = c[i + 1] + a[i];
  }

  for (int i = 0; i < n; ++i) {
    if (b[i] == c[i] and i != 0 and i != n - 1) {
      cout << i + 1 << endl;
      return;
    }
  }
  cout << -1 << endl;
  return;
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
  int t;
  cin >> t;
  while (t--) {
    solve(tc);
    tc++;
  }
}