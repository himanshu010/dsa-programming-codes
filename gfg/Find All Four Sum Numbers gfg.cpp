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

vector<vector<int>> fourSum(vector<int> &a, int k) {
  sort(a.begin(), a.end());
  int n = a.size();

  set<vector<int>> st;

  for (int i = 0; i < n - 3; ++i) {
    for (int j = i + 1; j < n - 2; ++j) {
      int l = j + 1, m = n - 1;
      while (l < m) {
        // cout << a[i] << ' ' << a[j] << ' ' << a[l] << ' ' << a[m] << endl;
        if (a[i] + a[j] + a[l] + a[m] == k) {
          vector<int> temp = {a[i], a[j], a[l], a[m]};
          st.insert(temp);
          l++;
          m--;
        }

        else if (a[i] + a[j] + a[l] + a[m] < k) {
          l++;
        } else {
          m--;
        }
      }
    }
  }

  vvi ans(st.begin(), st.end());

  return ans;
}

void solve(int tc) {
  int i, j, k, n, m, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vvi ans = fourSum(a, k);
  for (auto x : ans) {
    for (auto y : x) {
      cout << y << ' ';
    }
    cout << endl;
  }
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