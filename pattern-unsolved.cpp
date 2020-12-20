#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

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
    queue<string> st;
    string num;
    cin >> n;
    k = n + 1;
    while (k--) {
      getline(cin, num);
      st.push(num);
    }
    st.pop();
    while (!st.empty()) {
      sum = 0;
      string a = st.front();
      // cout<<a<<endl;
      int size = a.size();
      for (int i = 0; i < size; ++i) {

        a[i] = a[i] % 48;
        sum = sum + (a[i] * pow(2, (size - (i + 1))));
      }
      cout << sum << endl;

      st.pop();
    }
  }
}