class Solution
{
  public:
    int minJumps(int arr[], int n)
    {
        if (n == 1)
        {
            return 0;
        }
        int cur = arr[0];
        int jump = 1;
        int start = 1;

        while (cur < n)
        {
            if (start > cur)
            {
                return -1;
            }
            int mx = INT_MIN;
            for (int i = start; i <= cur; i++)
            {
                if (i >= n - 1)
                {
                    return jump;
                }

                mx = max(mx, arr[i]);
                mx--;
            }
            start = cur + 1;
            cur += mx + 1;
            jump += 1;
        }

        return jump;
    }
};
