#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int x, y;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  int ans = gcd(b, a % b);
  return ans;
}

void extendedEuclidianTheorem(int a, int b) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  extendedEuclidianTheorem(b, a % b);
  int Current_X = y;
  int Current_Y = x - (a / b) * y;
  x = Current_X;
  y = Current_Y;
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
    int a, b, c;

    // // Equation type:-
    // // ax+by=c
    // // And a, b, c are given and we have to calculate  x and y
    cin >> a >> b >> c;
    int ans = gcd(a, b);
    if ((c % ans) == 0) {
      int k = c / ans;
      extendedEuclidianTheorem(a, b);
      x = x * k;
      y = y * k;
      cout << "x= " << x << " " << endl << "y= " << y;
    } else {
      cout << "Not possible cause x & y should be in the form of integer"
           << endl;
    }
  }
}
