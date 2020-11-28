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
void solve(int tc) {
	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	int left, right;
	cin >> n >> left >> right;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int l = 0, r = n - 1;
	for (int i = 0; i < r;)
	{
		if (a[i] < left) {
			swap(a[i++], a[l++]);
		}
		else if (a[i] > right) {
			swap(a[i], a[r--]);
		}
		else {
			i++;
		}

	}

	for (auto x : a) {
		cout << x << ' ';
	}
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