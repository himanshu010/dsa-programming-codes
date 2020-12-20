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

const int N = 100005;

int cross_inversions_after_merging(int *a, int s, int e) {
  if (s == e) {
    return 0;
  }

  int mid = (s + e) / 2;

  int i = s;
  int j = mid + 1;
  int k = s;

  int cnt = 0;
  int temp[N];
  while (i <= mid and j <= e) {
    if (a[i] <= a[j]) {
      temp[k] = a[i];
      k++;
      i++;
    } else {
      temp[k++] = a[j++];
      cnt += mid - i + 1;
    }
  }

  while (i <= mid) {
    temp[k++] = a[i++];
  }
  while (j <= e) {
    temp[k++] = a[j++];
  }

  for (int i = s; i <= e; ++i) {
    a[i] = temp[i];
  }

  return cnt;
}

int inversion_count(int *a, int s, int e) {

  if (s == e) {
    return 0;
  }

  int mid = (s + e) / 2;

  int x = inversion_count(a, s, mid);
  int y = inversion_count(a, mid + 1, e);

  int z = cross_inversions_after_merging(a, s, e);

  return x + y + z;
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;

  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  cout << inversion_count(a, 0, n - 1);
}

int32_t main() {
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