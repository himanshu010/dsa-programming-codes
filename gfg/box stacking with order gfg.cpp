

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

int cur = 0;

bool compare(vector<int> a, vector<int> b) {
  if (a[0] * a[1] == b[0] * b[1]) {
    return a[2] > b[2];
  }
  return a[0] * a[1] > b[0] * b[1];
}

int maxHeight(int height[], int width[], int length[], int n, vi &postion,
              vvi &all) {
  for (int i = 0; i < n; i++) {
    int nnn = 3;
    int l, w, h;
    while (nnn--) {
      int ll = length[i];
      int ww = width[i];
      int hh = height[i];

      if (nnn == 2) {
        l = max(ll, ww);
        w = min(ll, ww);
        h = hh;
      }
      if (nnn == 1) {
        l = max(hh, ll);
        w = min(hh, ll);
        h = ww;
      }
      if (nnn == 0) {
        l = max(ww, hh);
        w = min(ww, hh);
        h = ll;
      }
      all.push_back({l, w, h});
    }
  }
  sort(all.begin(), all.end(), compare);
  vector<int> dp(3 * n);
  for (int i = 0; i < all.size(); i++) {
    dp[i] = all[i][2];
  }
  int mx = dp[0];

  for (int i = 1; i < all.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (all[i][0] < all[j][0] and all[i][1] < all[j][1] and
          dp[i] < dp[j] + all[i][2]) {
        dp[i] = dp[j] + all[i][2];
        postion[i] = j;
        if (mx < dp[i]) {
          mx = dp[i];
          cur = i;
          // if (postion[j] = -1) {
          //     postion[j] = 0;
          // }
          // postion[i] = postion[j] + 1;
          // if (cur < postion[i]) {
          //     cur = postion[i];
          //     index = i;
          // }
        }
      }
    }
  }

  return mx;
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  int l[n], w[n], h[n];
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> w[i] >> h[i];
  }
  vector<vector<int>> all;
  vector<int> postion(3 * n);
  for (int i = 0; i < 3 * n; ++i) {
    postion[i] = i;
  }
  cout << maxHeight(h, w, l, n, postion, all) << endl;
  bool flag = 1;
  while (flag) {
    cout << all[cur][0] << ' ' << all[cur][1] << ' ' << all[cur][2] << endl;
    if (cur == 0) {
      flag = 0;
    }
    cur = postion[cur];
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