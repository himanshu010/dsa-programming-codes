class Solution {
public:

  int checkSub(string &a, string &b) {
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
      return n;
    }
    return INT_MIN;
  }
  string findLongestWord(string S, vector<string> d) {
    int index = -1;
    int maxLen = 0;

    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++) {
      int len = checkSub(d[i], S);
      if (maxLen < len) {
        index = i;
        maxLen = len;
      }
    }
    if (index == -1) {
      return "";
    }
    return d[index];
  }
};