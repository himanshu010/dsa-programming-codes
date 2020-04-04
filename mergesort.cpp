#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

void merge(int *a, int s, int e) {
	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int k = s;

	int temp[100];

	while (i <= mid && j <= e) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}

	for (int i = s; i <= e; i++) {
		a[i] = temp[i];
	}
}

void mergeSort(int a[], int s, int e) {
	if (s >= e) {
		return;
	}
	int mid = (s + e) / 2;
	mergeSort(a, s, mid);
	mergeSort(a, mid + 1, e);

	//Merging the two functions
	merge(a, s, e);

}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt", "w" , stdout);
#endif

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	// int t;cin>>t;while(t--)
	{
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		mergeSort(a, 0, n - 1);
		for (auto x : a) {
			cout << x << ",";
		}


	}
}