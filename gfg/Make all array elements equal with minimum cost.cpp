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
using namespace std;

int findMinCost(vi a, int n) {
	int sum = 0;
	int mid;
	if (n & 1) {
		mid = a[n / 2];
	}
	else {
		mid = (a[n / 2] + a[n / 2 - 1]) / 2;
	}

	for (int i = 0; i < n; ++i)
	{
		sum += abs(mid - a[i]);
	}
	return sum;
}

void solve(int tc) {
	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	cout << findMinCost(a, n) << endl;

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
	int tc = 1;
	// int t;cin>>t;while(t--)
	{
		solve(tc);
		tc++;
	}
}