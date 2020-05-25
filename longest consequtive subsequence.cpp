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
#define moduli 998244353
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

int longestConsecutiveSubsequence(int *a, int n) {
    unordered_set<int> s;
    for (int i = 0; i < n; ++i)
    {
        s.insert(a[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s.find(a[i] - 1) != s.end()) {
            continue;
        }
        else {
            int count = 0;
            int x = a[i];
            while (s.find(x) != s.end()) {
                count++;
                x++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;

    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << longestConsecutiveSubsequence(a, n);


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
    // int t;cin>>t;while(t--)
    {
        int tc = 1;
        solve(tc);
        tc++;
    }
}