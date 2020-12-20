#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

bool isPrime(int n) {
  if (n == 1) {
    return false;
  } else {
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
  }
  return true;
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
    if (isPrime(n)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}