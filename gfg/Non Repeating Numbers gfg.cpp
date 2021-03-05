class Solution
{
  public:
    bool checkKthBitSet(int n, int k)
    {
        int i = 1;
        while (i < k)
        {
            n >>= 1;
            i++;
        }

        if (n & 1)
        {
            return true;
        }
        return false;
    }
    vector<int> singleNumber(vector<int> a)
    {
        int n = a.size();
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            x ^= a[i];
        }
        vector<int> ans(2);

        int rm = log2(x & (-x)) + 1;
        int b = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (checkKthBitSet(a[i], rm))
            {
                b ^= a[i];
            }
            else
            {
                c ^= a[i];
            }
        }

        ans[0] = min(b, c);
        ans[1] = max(b, c);
        return ans;
    }
};