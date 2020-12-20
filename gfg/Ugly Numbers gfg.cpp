// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

// } Driver Code Ends

// User function template for C++
class Solution {
public:
  // #define ull unsigned long long
  /* Function to get the nth ugly number*/
  ull getNthUglyNo(int n) {
    // code here

    vector<ull> a(n);
    a[0] = 1;
    ull i2 = 0, i3 = 0, i5 = 0;
    ull cnt = 1;
    while (cnt < n) {
      ull temp1 = a[i2] * 2;
      ull temp2 = a[i3] * 3;
      ull temp3 = a[i5] * 5;

      ull ans = min(temp1, min(temp2, temp3));
      if (ans == temp1) {
        i2++;
      }
      if (ans == temp2) {
        i3++;
      }
      if (ans == temp3) {
        i5++;
      }
      a[cnt] = ans;
      cnt++;
    }
    return a[n - 1];
  }
};

// { Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Solution ob;
    auto ans = ob.getNthUglyNo(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends