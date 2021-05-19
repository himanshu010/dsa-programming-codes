class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n <= 1)
        {
            return 0;
        }
        vector<int> pre(n), suff(n);
        pre[0] = 0;
        suff[n - 1] = 0;

        for (int i = 1; i < n; i++)
        {
            pre[i] = max(height[i - 1], pre[i - 1]);
            suff[n - 1 - i] = max(height[n - i], suff[n - i]);
        }

        int sum = 0;
        for (int i = 1; i < n - 1; i++)
        {
            sum += max(0, min(pre[i], suff[i]) - height[i]);
        }
        return sum;
    }
};