/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|         (himanshu010.github.io/Portfolio_website)         |
|                                                           |
|                                                           |
*-----------------------------------------------------------*


*/

#include<bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define R return

using namespace std;


int fib(int n, int *dp) {
    if (n == 0 or n == 1) {
        return n;
    }
    int ans;
    if (dp[n] != 0) {
        return dp[n];
    }
    ans = fib(n - 1, dp) + fib(n - 2, dp);
    dp[n] = ans;
    return ans;
}


int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        // cout << fib(5);
        cin >> n;
        int dp[100] = {0};
        cout << fib(n, dp) << endl;
        return 0;


    }
}