class Solution
{
  public:
    string sevenSegments(string s, int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = (int)s[i] - '0';
            if (temp == 0 or temp == 6)
            {
                sum += 6;
            }
            if (temp == 1)
            {
                sum += 2;
            }
            if (temp == 5 or temp == 2 or temp == 3 or temp == 9)
            {
                sum += 5;
            }
            if (temp == 4)
            {
                sum += 4;
            }
            if (temp == 7)
            {
                sum += 3;
            }
            if (temp == 8)
            {
                sum += 7;
            }
        }

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = 1;
        }
        sum -= (2 * n);
        int i = 0;
        while (sum - 4 >= 0 and i < n)
        {
            a[i] = 0;
            sum -= 4;
            i++;
        }
        i = n - 1;
        while (sum > 0 and i >= 0)
        {
            if (sum - 5 >= 0)
            {
                a[i] = 8;
                i--;
                sum -= 5;
            }
            else if (sum - 4 >= 0)
            {
                a[i] = 6;
                i--;
                sum -= 4;
            }
            else if (sum - 3 >= 0)
            {
                a[i] = 2;
                sum -= 3;
                i--;
            }
            else if (sum - 2 >= 0)
            {
                a[i] = 4;
                sum -= 2;
                i--;
            }
            else if (sum - 1 >= 0)
            {
                sum--;
                a[i] = 7;
                i--;
            }
        }

        string ans;
        for (auto x : a)
        {
            ans += (char)(x + (int)'0');
        }
        return ans;
    }
};