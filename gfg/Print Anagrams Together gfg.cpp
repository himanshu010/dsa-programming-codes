#define pb push_back

bool compare(pair<string, int> a, pair<string, int> b)
{
    if (a.first.compare(b.first) == 0)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

vector<vector<string>> Anagrams(vector<string> &a)
{
    vector<vector<string>> ans;
    int n = a.size();
    vector<pair<string, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        string temp1 = a[i];
        sort(temp1.begin(), temp1.end());
        v[i] = {temp1, i};
    }

    sort(v.begin(), v.end(), compare);
    vector<string> temp;
    temp.pb(a[v[0].second]);
    bool flag = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first.compare(v[i - 1].first) == 0)
        {
            temp.pb(a[v[i].second]);
            flag = 1;
        }
        else
        {
            ans.pb(temp);
            temp.clear();
            temp.pb(a[v[i].second]);
            flag = 0;
        }
    }
    if (temp.size() > 0)
    {
        ans.pb(temp);
    }

    return ans;
}