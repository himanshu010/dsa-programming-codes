class Solution
{
  public:
    bool checkTemp(vector<int> &temp, vector<int> &p)
    {
        for (int i = 0; i < 26; i++)
        {
            if (temp[i] != p[i])
            {
                return false;
            }
        }
        return true;
    }
    int search(string pat, string txt)
    {
        int n = txt.size();
        int m = pat.size();
        vector<int> p(26, 0), temp(26, 0);
        for (int i = 0; i < m; i++)
        {
            p[(int)pat[i] - 97]++;
        }

        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            temp[(int)txt[i] - 97]++;
        }
        if (checkTemp(temp, p))
        {
            sum++;
        }
        int i = 0, j = m;
        while (j < n)
        {
            temp[(int)txt[i] - 97]--;
            temp[(int)txt[j] - 97]++;
            if (checkTemp(temp, p))
            {
                sum++;
            }
            j++;
            i++;
        }
        return sum;
    }
};