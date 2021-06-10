class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        int maxReach = nums[0];
        int sLeft = maxReach;
        int jump = 1;
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                return jump;
            }

            maxReach = max(maxReach, i + nums[i]);

            sLeft--;
            if (sLeft == 0)
            {
                jump += 1;
                sLeft = maxReach - i;
            }
        }
        return jump;
    }
};