class Solution
{
  public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int n = word1.size();
        int m = word2.size();
        int i = 0, j = 0;
        int k = 0, l = 0;
        while (i < n and j < m)
        {
            while (k < word1[i].size() and l < word2[j].size())
            {
                if (word1[i][k] != word2[j][l])
                {
                    return 0;
                }
                k++;
                l++;
            }
            if (k == word1[i].size())
            {
                i++;
                k = 0;
            }
            if (l == word2[j].size())
            {
                j++;
                l = 0;
            }
        }
        if (k != 0 or l != 0 or i < n or j < m)
        {
            return 0;
        }
        return 1;
    }
};