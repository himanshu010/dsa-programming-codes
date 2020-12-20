#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define arr 100006
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define loop(i, x, n) for (int i = x; i < n; i++)
ll sumn(ll x) {
  ll s = 0;
  while (x != 0) {
    s += (x % 10);
    x /= 10;
  }
  return s;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  FIO;
  string s;
  cin >> s;
  ll sum = 0;
  if (s.length() == 1) {
    cout << 0;
    return 0;
  }
  for (ll i = 0; i < s.length(); i++) {
    sum = sum + (s[i] - '0');
  }

  ll c = 1;

  while (sum / 10 != 0) {
    cout << sum << endl;
    sum = sumn(sum);
    c++;
  }
  cout << c << endl;
  return 0;
}