class Solution
{
  public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> dp(n);
        dp[0] = {1, 1};
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            int mx1 = 0, mx2 = 0;
            if (nums[i] > nums[i - 1])
            {
                dp[i] = {dp[i - 1].second + 1, dp[i - 1].second};
            }
            else if (nums[i] < nums[i - 1])
            {
                dp[i] = {dp[i - 1].first, dp[i - 1].first + 1};
            }
            else
            {
                dp[i] = {dp[i - 1].first, dp[i - 1].second};
            }
        }
        return max(dp[n - 1].first, dp[n - 1].second);
    }
};