#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

vector<int> factors(vector<int> primes, int m) {

  vector<int> factor;
  int i = 0;
  int n = m;
  int p = primes[0];

  while (p * p <= n) {
    int sum = 0;

    if (m % p == 0) {
      factor.pb(p);

      while (m % p == 0) {
        m = m / p;
        sum++;
      }
      factor.pb(sum);
    }

    i++;
    p = primes[i];
  }
  if (m != 1) {
    factor.pb(m);
  }
  return factor;
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
    int b;

    cin >> b;
    if (b == 0 || b == 1) {
      cout << 0;
    } else {
      int A[b + 1] = {0};
      A[1] = 1;
      A[0] = 1;

      for (int i = 2; i * i <= b; ++i) {
        for (int j = 2 * i; j <= b; j += i) {
          A[j] = 1;
        }
      }
      vector<int> primes;
      for (int i = 0; i <= b; ++i) {
        if (A[i] == 0) {
          primes.pb(i);
        }
      }
      vector<int> factor;
      factor = factors(primes, b);
      if (factor.size() & 1) {
        factor.pb(1);
      }
      for (int i = 0; i < factor.size(); i += 2) {
        cout << factor[i] << " --> " << factor[i + 1] << " times" << endl;
      }
    }
  }
}