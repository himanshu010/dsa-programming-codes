#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int simpleCountBit(int n) {
  int ans = 0;
  while (n) {
    ans += (n & 1);
    n = n >> 1;
  }
  return ans;
}

int FastCountBit(int n) {
  int ans = 0;
  while (n > 0) {
    n = n & (n - 1);
    ans++;
  }
  return ans;
}

int InbuiltCountBit(int n) {
  int ans = __builtin_popcount(n);
  return ans;
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
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    cout << "By simple Method : " << simpleCountBit(n) << endl;
    cout << "By Fast Method : " << FastCountBit(n) << endl;
    cout << "By Inbuilt library : " << InbuiltCountBit(n);
  }
}