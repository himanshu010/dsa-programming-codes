bool compare(vector<int> a, vector<int> b) {
  if (a[0] * a[1] == b[0] * b[1]) {
    return a[2] > b[2];
  }
  return a[0] * a[1] > b[0] * b[1];
}
int maxHeight(int height[], int width[], int length[], int n) {
  vector<vector<int>> all;
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
        mx = max(dp[i], mx);
      }
    }
  }

  return mx;
}