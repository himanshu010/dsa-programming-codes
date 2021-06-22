/*
*-----------------------------------------------------------*
|               AUTHOR: Himanshu Aswal                      |
|             ( website: himanshuaswal.com )                |
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
#define PQ priority_queue
using namespace std;


void preCompute() {

}
void solve(int tc) {
    int j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());


    int i = 0, low = n - 1, high = n - 1;
    while (i < high) {
        low = max(i, low);
        while (low > i and a[i] + a[low] >= l) {
            low--;
        }
        while (high > low and a[i] + a[high] > r) {
            high--;
        }
        sum += (high - low);
        i++;
    }
    cout << sum << endl;
}
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    preCompute();
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}