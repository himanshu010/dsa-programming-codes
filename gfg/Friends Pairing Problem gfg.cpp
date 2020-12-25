#define moduli 1000000007
class Solution
{
  public:
    long long int findAllConfig(vector<long long int> &dp, long long int n)
    {
        if (dp[n] != -1)
        {
            return dp[n];
        }

        if (n <= 2)
        {
            return n;
        }

        return dp[n] = (findAllConfig(dp, n - 1) % moduli + ((n - 1) * findAllConfig(dp, n - 2) % moduli) % moduli) %
                       moduli;
    }
    void solve(long long int tc)
    {
        long long int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        vector<long long int> dp(100005, -1);

        cout << findAllConfig(dp, n);
    }
    long long int countFriendsPairings(long long int n)
    {
        vector<long long int> dp(n + 1, -1);
        return findAllConfig(dp, n);
    }
};
