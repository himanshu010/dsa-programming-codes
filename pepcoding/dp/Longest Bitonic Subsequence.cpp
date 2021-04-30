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
	int i, j, k, n, m, ans = 1, cnt = 0, sum = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}


	vector<int> pre(n), suff(n);
	pre[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		int temp = 0;
		for (int j = 0; j < i; ++j)
		{
			if (a[i] > a[j]) {
				temp = max(temp, pre[j]);
			}
		}
		pre[i] = temp + 1;

	}

	suff[n - 1] = 1;
	for (int i = n - 2; i >= 0; --i)
	{
		int temp = 0;
		for (int j = n - 1; j > i; --j)
		{
			if (a[i] > a[j]) {
				temp = max(temp, suff[j]);
			}
		}
		suff[i] = temp + 1;
	}
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, suff[i] + pre[i] - 1);
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