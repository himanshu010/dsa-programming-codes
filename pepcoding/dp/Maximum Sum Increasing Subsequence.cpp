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

bool compare(P a, P b) {
	return a.S != b.S ? a.S < b.S : a.F < b.S;
}

void solve(int tc) {
	int i, j, k, n, m, ans = 1, cnt = 0, sum = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}


	vector<int> dp(n);
	dp[0] = a[0];
	ans = dp[0];
	for (int i = 1; i < n; ++i)
	{
		int temp = 0;
		for (int j = 0; j < i; ++j)
		{
			if (a[i] >= a[j]) {
				temp = max(temp, dp[j]);
			}
		}

		dp[i] = temp + a[i];
		ans = max(ans, dp[i]);
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