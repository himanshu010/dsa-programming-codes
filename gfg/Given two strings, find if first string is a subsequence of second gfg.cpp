#include <iostream>
#include<vector>
using namespace std;


bool solve() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int m = b.size();

  int i = 0, j = 0;

  while (i < n and j < m) {
    if (a[i] == b[j]) {
      i++;
      j++;
    }
    else {
      j++;
    }
  }
  if (i == n) {
    return true;
  }
  return false;
}

int main() {
  int t; cin >> t; while (t--)
  {
    cout << solve() << endl;
  }
  return 0;
}