#include <bits/stdc++.h>
using namespace std;

int cs(int n)
{
    vector<int> dp(n + 1, 1);
    if (n < 2)
    {
        return dp[n];
    }

    for (int i = 2; i <= n; i++)
    {
        int a = 0, b = 0, c = 0;
        if (i - 3 >= 0)
        {
            c = dp[i - 3];
        }
        if (i - 2 >= 0)
        {
            b = dp[i - 2];
        }
        a = dp[i - 1];
        dp[i] = a + b + c;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << cs(n) << endl;
}