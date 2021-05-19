class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>>dp(n, {1, 1});
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if ((i - 1) & 1) {
                if (arr[i - 1] > arr[i]) {
                    dp[i].first = dp[i - 1].first + 1;
                }
                if (arr[i - 1] < arr[i]) {
                    dp[i].second = dp[i - 1].second + 1;
                }
            }
            else {
                if (arr[i - 1] > arr[i]) {
                    dp[i].second = dp[i - 1].second + 1;
                }
                if (arr[i - 1] < arr[i]) {
                    dp[i].first = dp[i - 1].first + 1;
                }
            }
            ans = max({dp[i].first, dp[i].second, ans});
        }

        return ans;
    }
};