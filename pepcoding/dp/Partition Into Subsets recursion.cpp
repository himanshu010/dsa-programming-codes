/*
*-----------------------------------------------------------*
|               AUTHOR: Himanshu Aswal                      |
|             ( website: himanshuaswal.com )                |
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
#define PQ priority_queue
using namespace std;

int findWays(int n, int k, vvi &dp) {
    if (dp[n][k] != -1) {
        return dp[n][k];
    }
    if (k == 1) {
        return 1;
    }

    if (n == k) {
        return 1;
    }

    int sum = 0;
    sum += (k * findWays(n - 1, k, dp));
    sum += findWays(n - 1, k - 1, dp);

    return dp[n][k] = sum;
}


void preCompute() {

}
void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
    cout << findWays(n, k, dp);
}
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    preCompute();
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}