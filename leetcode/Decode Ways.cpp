class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n);
        dp[0] = 1;

        if (n > 1) {
            if (s[1] == '0') {
                if (s[0] > '2') {
                    return 0;
                }
                dp[1] = 1;
            }
            else {
                if (s[0] == '1' or (s[0] == '2'  and s[1] <= '6')) {
                    dp[1] = 2;
                }
                else {
                    dp[1] = 1;
                }
            }
        }

        for (int i = 2; i < n; i++) {
            if (s[i] == '0') {
                if (s[i - 1] > '2' or s[i - 1] == '0') {
                    return 0;
                }
                dp[i] = dp[i - 2];
            }
            else {
                dp[i] = dp[i - 1];
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                    dp[i] += dp[i - 2];
                }
            }
        }

        return dp[n - 1];
    }
};