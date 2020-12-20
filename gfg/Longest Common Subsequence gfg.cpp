int sol(int x, int y, string s1, string s2, vector<vector<int>> &dp) {
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  if (x == 0 or y == 0) {
    return 0;
  }

  if (s1[x - 1] == s2[y - 1]) {
    return dp[x][y] = 1 + sol(x - 1, y - 1, s1, s2, dp);
  } else {
    return dp[x][y] = max(sol(x - 1, y, s1, s2, dp), sol(x, y - 1, s1, s2, dp));
  }
}

int lcs(int x, int y, string s1, string s2) {
  vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
  return sol(x, y, s1, s2, dp);
}