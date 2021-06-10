class Solution
{
  public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 0});
        dp[0] = {1, 1};
        for (int i = 1; i < n; i++)
        {
            int mx = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (mx == dp[j].first)
                    {
                        dp[i].second += dp[j].second;
                    }
                    else if (mx < dp[j].first)
                    {
                        mx = dp[j].first;
                        dp[i].second = dp[j].second;
                    }
                }
            }
            dp[i].first = mx + 1;
            dp[i].second = max(dp[i].second, 1);
        }

        int ans = 0;
        int mx = 0;
        for (auto x : dp)
        {
            if (mx == x.first)
            {
                ans += x.second;
            }
            else if (mx < x.first)
            {
                mx = x.first;
                ans = x.second;
            }
        }

        return ans;
    }
};