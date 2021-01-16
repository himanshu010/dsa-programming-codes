class Solution
{
  public:
    long long bfs(long long src, long long x)
    {
        queue<long long> qu;
        long long ans = 0;
        for (long long i = 1; i <= 9; i++)
        {
            qu.push(i);
        }

        while (!qu.empty())
        {
            long long cur = qu.front();
            qu.pop();
            if (cur > x)
            {
                return ans;
            }
            else
            {
                ans = cur;
            }
            long long ld = cur % 10;

            if (ld == 0)
            {
                qu.push((cur * 10) + (ld + 1));
            }
            else if (ld == 9)
            {
                qu.push((cur * 10) + (ld - 1));
            }
            else
            {
                qu.push((cur * 10) + (ld - 1));
                qu.push((cur * 10) + (ld + 1));
            }
        }
    }

    long long jumpingNums(long long x)
    {
        return bfs(0LL, x);
    }
};