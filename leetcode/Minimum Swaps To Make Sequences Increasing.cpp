class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pair<int, int>>dp(n, {INT_MAX, INT_MAX});
        dp[0] = {0, 1};
        for (int i = 1; i < n; i++) {
            if (nums1[i] > nums1[i - 1] and nums2[i] > nums2[i - 1]) {
                dp[i].first = min(dp[i - 1].first, dp[i].first);
            }
            if (nums1[i] > nums2[i - 1] and nums2[i] > nums1[i - 1]) {
                dp[i].first = min(dp[i].first, dp[i - 1].second);
            }


            if (nums2[i] > nums1[i - 1] and nums1[i] > nums2[i - 1]) {
                dp[i].second = min(dp[i - 1].first + 1, dp[i].second);
            }
            if (nums2[i] > nums2[i - 1] and nums1[i] > nums1[i - 1]) {
                dp[i].second = min(dp[i - 1].second + 1, dp[i].second);
            }

        }
        return min(dp[n - 1].first, dp[n - 1].second);
    }
};