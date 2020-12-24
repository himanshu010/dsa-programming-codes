/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|     ( website: himanshu010.github.io/Portfolio_website )  |
|                                                           |
|                                                           |
*-----------------------------------------------------------*
*/
#include <bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_ma

using namespace std;

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  string s;
  cin >> s;
  n = s.size();
  cin >> k;

  i = 1;
  string a;
  a += s[0];
  string op;
  string no;

  while (i < n) {
    if ((int)s[i] - 48 >= 0 and (int)s[i] - 48 <= 9) {
      no += s[i];
      if (i + 1 < n) {
        while ((int)s[i + 1] - 48 >= 0 and (int)s[i + 1] - 48 <= 9) {
          no += s[i + 1];
          i++;
          if (i + 1 >= n) {
            break;
          }
        }
      }
      j = 0;
      m = no.size();
      cnt = m;
      int temp = 0;
      while (j < m) {
        temp += ((int)no[j] - 48) * pow(10, cnt - 1);
        cnt--;
        j++;
      }
      for (int i = 0; i < temp; ++i)
      {
        op += a;
      }
      a = "";
      no = "";
    }
    else {
      a += s[i];
    }
    i++;
  }

  cout << op[k + 1] << endl;
}
int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;

  // int t;cin>>t;while(t--)
  {
    solve(tc);
    tc++;
  }
}