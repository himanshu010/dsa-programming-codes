int minDeletions(string s, int n) {
    vector<vector<int>>dp(n, vector<int>(n));
    int i = 0;
    int j = 0;
    int dif = 0;
    while (j - i < n) {
        while (j < n) {
            if (i == j) {
                dp[i][j] = 1;
            }
            else if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }

            j++;
            i++;
        }
        dif += 1;
        i = 0;
        j = i + dif;

    }
    return n - dp[0][n - 1];
}