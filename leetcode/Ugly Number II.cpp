class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int x = 0, y = 0, z = 0;
        int a, b, c;
        for (int i = 1; i < n; i++) {
            a = dp[x] * 2;
            b = dp[y] * 3;
            c = dp[z] * 5;

            dp[i] = min({a, b, c});
            if (a == dp[i]) {
                x++;
            }
            if (b == dp[i]) {
                y++;
            }
            if (c == dp[i]) {
                z++;
            }
        }
        return dp[n - 1];
    }
};