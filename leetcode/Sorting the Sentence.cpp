class Solution
{
  public:
    string sortSentence(string s)
    {
        vector<string> words;

        stringstream check1(s);

        string im;

        while (getline(check1, im, ' '))
        {
            words.push_back(im);
        }

        map<int, string> mp;
        for (auto x : words)
        {
            int m = x.size();
            int t = x[m - 1] - '0';
            mp[t] = x.substr(0, m - 1);
        }
        string ans;
        for (auto x : mp)
        {
            ans += x.second + " ";
        }

        return ans.substr(0, ans.size() - 1);
    }
};