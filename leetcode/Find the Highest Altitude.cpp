class Solution
{
  public:
    int largestAltitude(vector<int> &gain)
    {
        if (gain.size() == 0)
        {
            return 0;
        }
        int n = gain.size();
        vector<int> prefix(gain.size() + 1);
        prefix[0] = 0;
        int mx = 0;
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + gain[i - 1];
            mx = max(mx, prefix[i]);
        }
        return mx;
    }
};