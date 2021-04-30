/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.codes )               |
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
#define PQ priority_queue
using namespace std;

void solve(int tc) {
	int i, j, k, n, m, ans = INT_MAX, cnt = 0, sum = 0;
	cin >> n;
	vector<vector<int>>dp(n, vector<int>(3)), a(n, vector<int>(3));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> a[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; ++j)
		{
			if (i == 0) {
				dp[i][j] = a[i][j];
				continue;
			}
			int d = dp[i - 1][0], b = dp[i - 1][1], c = dp[i - 1][2];
			if (j == 0) {
				d = INT_MAX;;
			}
			if (j == 1) {
				b = INT_MAX;
			}
			if (j == 2) {
				c = INT_MAX;
			}

			dp[i][j] = min(d, min(b, c)) + a[i][j];
		}
	}

	for (auto x : dp[n - 1]) {
		ans = min(x, ans);
	}
	cout << ans << endl;


}
int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc = 1;
	// int t;cin>>t;while(t--)
	{
		solve(tc);
		tc++;
	}
}