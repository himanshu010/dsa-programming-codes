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
#define vvi vector<vector<int>> #define vb vector<bool>
#define um unordered_map
using namespace std;
void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  int *a = new int[n];

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int repeating, missing;
  for (int i = 0; i < n; ++i) {
    if (a[abs(a[i]) - 1] < 0) {
      repeating = abs(a[i]);
    } else {
      a[abs(a[i]) - 1] *= -1;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      missing = i + 1;
      break;
    }
  }

  cout << missing << ' ' << repeating << endl;
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