#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int ARR[10000];
int tree[10000];


void update(int i, int inc, int N) {
    while (i <= N) {
        BIT[i] = max(BIT[i], inc);
        i += (i & (-i));
        // cout << i << "==========" << endl;
    }
}

int query(int i) {
    int ans;
    int temp = 0;
    while (i > 0) {
        // cout << temp << " " << BIT[i] << "==============" << endl << endl;
        ans = max(BIT[i], temp);
        // cout << ans << "----" << endl;
        temp = ans;
        // cout << temp << "+++++" << endl;
        i -= (i & (-i));
    }
    return ans;

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
        int i, j, k, n, q, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            update(i, a[i], n);
        }
        // cout << query(7) << endl;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l;
            cout << query(l) << endl;
        }
    }
}