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

void printArray(vector<int> c, int n) {
  for (int i = 0; i < n; ++i) {
    cout << c[i] << ' ';
  }
  cout << endl;
}

void generate_arrays(vi a, vi b, vi c, int i, int j, int n, int m, int length,
                     bool flag) {
  if (flag) {
    if (length != 0) {
      printArray(c, length + 1);
    }
    for (int k = i; k < n; ++k) {
      if (length == 0) {
        c[length] = a[k];
        generate_arrays(a, b, c, k + 1, j, n, m, length, !flag);
      } else {
        if (a[k] > c[length]) {
          c[length + 1] = a[k];
          generate_arrays(a, b, c, k + 1, j, n, m, length + 1, !flag);
        }
      }
    }
  } else {
    for (int l = j; l < m; ++l) {
      if (b[l] > c[length]) {
        c[length + 1] = b[l];
        generate_arrays(a, b, c, i, l + 1, n, m, length + 1, !flag);
      }
    }
  }
}
void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<int> c(n + m);
  generate_arrays(a, b, c, 0, 0, n, m, 0, 1);
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