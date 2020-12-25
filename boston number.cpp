#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

vector<int> primes;

int DigitSum(int n)
{
    int sum = 0;
    int ten = 10;
    while (n > 0)
    {
        int lastDig = n % 10;
        sum += lastDig;
        n = (n - lastDig) / 10;
    }
    return sum;
}

void primefactorisation(int n)
{
    if (n % 2 == 0)
    {
        while (n % 2 == 0)
        {
            primes.pb(2);
            n = n / 2;
        }
    }

    for (int i = 3; i <= n; i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                primes.pb(i);
                n = n / i;
            }
        }
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;

        cin >> n;
        int copyN = n;
        primefactorisation(copyN);
        for (int i = 0; i < primes.size(); i++)
        {
            ans = DigitSum(primes[i]);
            primes[i] = ans;
        }
        for (auto x : primes)
        {
            sum += x;
        }
        ans = DigitSum(n);
        if (sum == ans)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}