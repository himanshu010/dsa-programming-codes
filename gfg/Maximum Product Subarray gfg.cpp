
long long maxProduct(int *a, int n)
{
    vector<pair<long long, long long>> dp(n);

    dp[0] = {a[0], a[0]};
    long long maximum = a[0];
    long long maxp, minp;
    for (long long i = 1; i < n; ++i)
    {
        if (a[i] < 0)
        {
            long long temp;
            temp = dp[i - 1].first;
            dp[i - 1].first = dp[i - 1].second;
            dp[i - 1].second = temp;
        }
        maxp = max<long long>(dp[i - 1].first * a[i], a[i]);
        minp = min<long long>(dp[i - 1].second * a[i], a[i]);
        dp[i] = {maxp, minp};
        //  cout<<maxp<<' '<<minp<<endl;
        maximum = max<long long>(maximum, maxp);
    }
    return maximum;
}