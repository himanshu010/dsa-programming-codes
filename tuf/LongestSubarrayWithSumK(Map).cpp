/*
╭──────────────────────────────────────────────╮
│  Author : Himanshu Aswal                     │
│  Web    : https://himanshuaswal.com          │
╰──────────────────────────────────────────────╯
*/

#include<bits/stdc++.h>
#define moduli 998244353
#define ll long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define PQ priority_queue
#define endl "\n"
using namespace std;

void preCompute() {

}

int longestSubarray(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    long long sum = 0, n = nums.size(), ans = 0;
    for (long long i = 0; i < n; ++i)
    {
        sum += nums[i];
        if (mp.find(sum) == mp.end()) mp[sum] = i;
        if (sum == k) {
            ans = max(ans, i + 1);
        }
        if (mp.find(sum - k) != mp.end()) {
            ans = max(ans, i - mp[sum - k]);
        }
    }
    return ans;
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int b; cin >> b;
    cout << longestSubarray(a, b) << endl;

}
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    preCompute();
    int tc = 1;
    int t; cin >> t; while (t--)
    {
        solve(tc);
        tc++;
    }
}