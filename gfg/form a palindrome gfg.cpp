#include<bits/stdc++.h>
using namespace std;

int longPal(string a, int s, int e, vector<vector<int>>&dp) {
    if (dp[s][e] != -1) {
        return dp[s][e];
    }

    if (s == e) {
        return 1;
    }
    if (s > e) {
        return 0;
    }

    if (a[s] == a[e]) {
        return dp[s][e] = 2 + longPal(a, s + 1, e - 1, dp);
    }
    return dp[s][e] = max(longPal(a, s + 1, e, dp), longPal(a, s, e - 1, dp));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t; cin >> t; while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        cout << n - longPal(s, 0, n - 1, dp) << endl;
    }
    return 0;
}