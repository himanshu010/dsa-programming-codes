class Solution
{
  public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        vector<long long int> ans;
        int gcd = __gcd(L, B);
        ans.push_back((L / gcd) * (B / gcd));
        ans.push_back(gcd);

        return ans;
    }
};