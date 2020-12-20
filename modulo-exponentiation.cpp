#include <bits/stdc++.h>
using namespace std;

long long int c = 1e9 + 7;

long long int power(long long int x, long long int y) {
  long long int res = 1;

  while (y) {

    if (y & 1) {
      res *= x;
      res %= c;
    }

    x *= x;
    x %= c;

    y /= 2;
  }

  return res;
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  // code
  cout << power(2, 8);
}