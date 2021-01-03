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
#include<bits/stdc++.h>
#define moduli 1000000007
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
using namespace std;

int countSubsequences(string s) {
  int n = s.size();
  int a = 0;
  int b = 0;
  int c = 0;

  for (int i = 0; i < n; ++i)
  {
    if (s[i] == 'a') {
      a = ((a * 2) % moduli + 1) % moduli;
    }
    if (s[i] == 'b') {
      b = ((2 * b) % moduli + a) % moduli;
    }
    if (s[i] == 'c') {
      c = ((2 * c) % moduli + b) % moduli;
    }
  }
  return c;
}
void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  string s;
  cin >> s;


  countSubsequences(string s);



}
int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  // int t;cin>>t;while(t--)
  {
    solve(tc);
    tc++;
  }
}