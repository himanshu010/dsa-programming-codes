class Solution {
public:
    int kadane(vector<int> a, int n) {
        vector<int> dp(n);
        dp[0] = a[0];
        int mx = a[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + a[i], a[i]);
            mx = max(mx, dp[i]);
        }

        return mx;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans1 = kadane(nums, n);
        for (int i = 0; i < n; i++) {
            nums[i] *= -1;
        }
        int ans2 = kadane(nums, n);
        return max(ans1, ans2);

    }
};