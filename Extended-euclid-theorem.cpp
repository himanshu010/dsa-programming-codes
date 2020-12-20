#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int x, y;

void extendedEuclidTheorem(int a, int b) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }

  extendedEuclidTheorem(b, a % b);

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
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    int a, b;
    cin >> a >> b;

    extendedEuclidTheorem(a, b);
    cout << x << "," << y;
  }
}