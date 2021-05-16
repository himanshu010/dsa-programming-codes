/*
*-----------------------------------------------------------*
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.com )                 |
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
#define um unordered_map
#define PQ priority_queue
using namespace std;

void preCompute()
{
}

int calculateDepth(string s, int n, int &i)
{
    if (s[i] == 'l' or i >= n)
    {
        return 0;
    }
    i++;
    int left = calculateDepth(s, n, i);
    i++;
    int right = calculateDepth(s, n, i);

    return max(left, right) + 1;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    string s;
    cin >> s;
    n = s.size();
    i = 0;
    cout << calculateDepth(s, n, i) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    preCompute();
    int tc = 1;
    int t;
    cin >> t;
    while (t--)
    {
        solve(tc);
        tc++;
    }
}