#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    int no, mu, ko;
    cin >> no >> mu >> ko;
    for (int i = 0; i < no; i++) {
      for (int j = 0; j < ko; j++) {
        int a;
        cin >> a;
      }
    }
    srand(time(0));
    for (int i = 0; i < no; i++) {
      cout << rand() % mu + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}