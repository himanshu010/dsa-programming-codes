class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = nums[1];
        int mx = dp[0];
        int ans = max(dp[0], dp[1]);
        for (int i = 2; i < n; i++)
        {
            mx = max(mx, dp[i - 2]);
            dp[i] = mx + nums[i];
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};