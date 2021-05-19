class Solution
{
  public:
    int minimumLength(string s)
    {
        int n = s.size();
        vector<pair<char, int>> v;
        int sum = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                sum += 1;
            }
            else
            {
                v.push_back({s[i - 1], sum});
                sum = 1;
            }
        }
        if (sum != 0)
        {
            v.push_back({s[n - 1], sum});
        }
        if (v.size() == 1)
        {
            if (v[0].second == 1)
            {
                return 1;
            }
            return 0;
        }

        int i = 0;
        int j = v.size() - 1;
        while (i < j)
        {
            if (v[i].first == v[j].first)
            {
                i++;
                j--;
            }
            else
            {
                break;
            }
        }
        if (i == j)
        {
            if (v[i].second % 2 == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        int cnt = 0;

        for (int k = i; k <= j; k++)
        {
            cnt += v[k].second;
        }
        return cnt;
    }
