bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
vector<pair<int, int>> overlappedInterval(vector<pair<int, int>> vec, int n)
{
    sort(vec.begin(), vec.end(), compare);

    int s = vec[0].first, e = vec[0].second;
    vector<pair<int, int>> ans;
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (e >= vec[i].first)
        {
            e = max(e, vec[i].second);
            flag = true;
        }
        else
        {
            ans.push_back({s, e});
            s = vec[i].first;
            e = vec[i].second;
            flag = false;
        }
    }

    ans.push_back({s, e});
    return ans;
}