#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;cin>>t;while(t--)
  {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    queue<int> qu;
    int A[] = {1, 2, 3, 2, 2, 3, 2, 3, 4};
    n = sizeof(A) / sizeof(int);
    for (int i = 0; i < n; ++i) {
      qu.push(A[i]);
    }
    while (!qu.empty()) {
      cout << qu.front() << endl;
      qu.pop();
    }
  }
}