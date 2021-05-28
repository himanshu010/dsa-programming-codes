class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int i = 0, j = 0, diff = 0;;
        while (j - i < n) {
            while (j < n) {
                if (i == j) {
                    dp[i][j] = piles[i];
                }
                else if (i + 1 == j) {
                    dp[i][j] = max(dp[i][i], dp[j][j]);
                }
                else {
                    dp[i][j] = max(dp[i][i] + min(dp[i + 2][j], dp[i + 1][j - 1]), dp[j][j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
                }
                i++;
                j++;
            }
            diff += 1;
            i = 0;
            j = i + diff;
        }
        return accumulate(piles.begin(), piles.end(), 0) - 2 * dp[0][n - 1] < 0;
    }
};