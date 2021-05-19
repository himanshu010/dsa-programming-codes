class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1 or (i == 0 and j == 0)) {
                    continue;
                }
                int a = 0, b = 0;
                if (i - 1 >= 0) {
                    a = dp[i - 1][j];
                }
                if (j - 1 >= 0) {
                    b = dp[i][j - 1];
                }
                dp[i][j] = a + b;
            }
        }
        return dp[n - 1][m - 1];
    }
};