class Solution {
public:
    vector<pair<int, int>> moves = {{ -2, -1}, { -2, 1}, { -1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, { -1, -2}};
    bool isValid(int r, int c, int n) {
        return (r >= 0 and r<n and c >= 0 and c < n);
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>>dp(n, vector<double> (n, 0));
        vector<vector<double>>dp2(n, vector<double> (n, 0));
        dp[row][column] = 1;
        while (k--) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] != 0) {
                        for (auto x : moves) {
                            if (isValid(i + x.first, j + x.second, n)) {
                                dp2[i + x.first][j + x.second] += dp[i][j] / 8;
                            }
                        }
                    }
                    dp[i][j] = 0;
                }
            }

            dp = dp2;
            dp2.clear();
            dp2.resize(n);
            for (int i = 0; i < n; i++) {
                dp2[i].resize(n);
                fill(dp2[i].begin(), dp2[i].end(), 0);
            }
        }
        double sum = 0;

        for (auto x : dp) {
            for (auto y : x) {
                sum += y;
            }
        }
        return sum;
    }
};