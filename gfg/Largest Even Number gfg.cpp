class Solution {
public:
  string LargestEven(string s) {
    int n = s.size();
    vector<int> a(10, 0);
    for (int i = 0; i < n; i++) {
      a[(int)(s[i] - '0')]++;
    }
    string ans;
    int minE = INT_MIN;

    for (int i = 0; i < 10; i++) {
      if (a[i] != 0 and i % 2 == 0) {
        minE = i;
        a[i]--;
        break;
      }
    }
    for (int i = 9; i >= 0; i--) {
      if (a[i] != 0) {
        while (a[i] > 0) {
          ans += (char)(i + 48);
          a[i]--;
        }
      }
    }
    if (minE == INT_MIN) {
      return ans;
    }
    ans += (char)(minE + 48);
    return ans;
  }
};