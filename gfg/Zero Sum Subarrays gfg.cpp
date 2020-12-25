ll findSubarray(vector<ll> arr, int n)
{
    ll sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
        if (mp.find(temp) != mp.end())
        {
            sum += mp[temp];
            mp[temp]++;
        }
        else
        {
            mp[temp]++;
        }
    }
    return sum;
}