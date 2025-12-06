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
    ll left = 0, right = 0, sum = nums[0], n = nums.size(), ans = 0;
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= nums[left++];
        }
        if (sum == k) {
            ans = max(ans, right - left + 1);
        }
        right++;
        if (right < n) sum += nums[right];

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