#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back



int partition(int a[], int s, int e) {
	int i = s - 1;
	int j = s;
	int pivot = a[e];
	for (; j < e; j++) {
		if (a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[e]);
	return i + 1;

}

void quickSort(int a[], int s, int e , string part) {
	if (s >= e) {
		return;
	}

	int p = partition(a, s, e);
	quickSort(a, s, p - 1, "left");
	quickSort(a, p + 1, e, "right");
	for (int i = 0; i <= e; i++) {
		cout << a[i] << "  ";
	}
	cout << part << endl;

}




int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt", "w" , stdout);
#endif

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n;

	// int t;cin>>t;while(t--)
	{
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		quickSort(a, 0, n - 1, "whole");
		for (int i = 0; i < n; ++i) {
			cout << a[i] << "  ";
		}
	}
}