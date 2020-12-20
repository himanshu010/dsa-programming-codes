#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

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
    int a, b;

    cin >> a >> b;
    // sieve();
    int A[b + 1] = {0};

    for (int i = 2; i * i <= b; ++i) {
      for (int j = 2 * i; j <= b; j += i) {
        A[j] = 1;
        A[0] = A[1] = 1;
        // cout<<j<<endl;
      }
    }
    cout << "primes are :-" << endl;
    for (int i = a; i <= b; ++i) {
      if (A[i] == 0) {
        cout << i << endl;
        sum++;
      }
    }
    cout << "total primes  are: " << sum << endl;
  }
}