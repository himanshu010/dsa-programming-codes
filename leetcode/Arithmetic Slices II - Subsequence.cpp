#include <bits/stdc++.h>
class Solution
{
  public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        vector<map<long long, long long>> dp(n + 1);
        long long sum = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((long long)nums[i] - (long long)nums[j] <= INT_MIN or
                    (long long) nums[i] - (long long)nums[j] >= INT_MAX)
                {
                    continue;
                }
                if (dp[j].count(nums[i] - nums[j]))
                {
                    sum += dp[j][nums[i] - nums[j]];
                    dp[i][nums[i] - nums[j]] += dp[j][nums[i] - nums[j]] + 1;
                }
                else
                {
                    dp[i][nums[i] - nums[j]] += 1;
                }
            }
        }
        return sum;
    }
};