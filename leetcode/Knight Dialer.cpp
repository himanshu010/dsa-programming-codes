#define moduli 1000000007
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> moveFrom = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, { -1, -1}, {1, 7, 0}, {2, 6}, {3, 1}, {2, 4}};
        int sum = 0;
        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                if (moveFrom[j][0] != -1) {
                    for (auto x : moveFrom[j]) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][x]) % moduli;
                    }
                }

            }
        }

        for (auto x : dp[n]) {
            sum = (sum + x) % moduli;
        }

        return sum;
    }
};