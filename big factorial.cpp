/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|     ( website: himanshu010.github.io/Portfolio_website )  |
|                                                           |
|                                                           |
*-----------------------------------------------------------*

*/

#include <bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map

using namespace std;

void multiply(int *a, int &n, int no)
{
    int carry = 0;
    for (int i = 0; i < n; ++i)
    {
        int product = a[i] * no + carry;

        a[i] = product % 10;
        carry = product / 10;
    }
    while (carry)
    {
        a[n] = carry % 10;
        carry = carry / 10;
        n++;
    }
}

void bigFactorial(int number)
{
    int *a = new int[100005];

    for (int i = 0; i < 1000; ++i)
    {
        a[i] = 0;
    }

    a[0] = 1;

    int n = 1;

    for (int i = 2; i <= number; ++i)
    {
        multiply(a, n, i);
    }

    for (int i = n - 1; i >= 0; --i)
    {
        cout << a[i];
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    bigFactorial(n);
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
    // int t;cin>>t;while(t--)
    {
        int tc = 1;
        solve(tc);
        tc++;
    }
}