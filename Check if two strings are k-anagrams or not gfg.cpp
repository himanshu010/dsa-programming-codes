#include <vector>

bool areKAnagrams(string str1, string str2, int k) {
  vector<int> a(26, 0);
  vector<int> b(26, 0);

  int n = str1.size();
  int m = str2.size();
  if (m != n) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    a[(int)str1[i] - 97]++;
  }
  for (int i = 0; i < m; i++) {
    b[(int)str2[i] - 97]++;
  }
  int pos = 0, neg = 0;
  for (int i = 0; i < 26; i++) {
    if (a[i] < b[i]) {
      neg += b[i] - a[i];
    } else if (a[i] > b[i]) {
      pos += a[i] - b[i];
    }
  }

  if (pos == neg and pos <= k) {
    return true;
  }
  return false;
}