class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n);
        dp[0] = {1, 1};
        int ans = 1;
        for (int i = 1; i < n; i++) {
            int mx1 = 0, mx2 = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    mx1 = max(mx1, dp[j].second);
                }
                if (nums[j] > nums[i]) {
                    mx2 = max(mx2, dp[j].first);
                }
            }

            dp[i] = {mx1 + 1, mx2 + 1};

            ans = max({ans, mx1 + 1, mx2 + 1});
        }
        return ans;
    }
};