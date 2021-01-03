class Solution
{
public:
  int patternCount(string s)
  {
    int n = s.size();
    int sum = 0;
    bool o1 = 0;
    int zero = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (zero == 0) {
          o1 = 1;
        }
        else if (zero != 0 and o1) {
          sum++;
          zero = 0;
        }
      }
      else if (s[i] == '0' and o1) {
        zero++;
      }
      else {
        o1 = 0;
        zero = 0;
      }
    }
    return sum;
  }

};