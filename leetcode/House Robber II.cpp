class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n), dp1(n, 0);
        int mx = INT_MIN;
        int mx2 = 0;
        if (n == 1)
        {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp1[0] = 0;
        dp1[1] = nums[1];
        int ans = max(dp[0], dp[1]);
        for (int i = 2; i < n; i++)
        {
            mx2 = max(mx2, dp1[i - 2]);
            mx = max(mx, dp[i - 2]);
            dp[i] = mx + nums[i];
            dp1[i] = mx2 + nums[i];
            if (i == n - 1)
            {
                ans = max(ans, dp1[i]);
                continue;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};