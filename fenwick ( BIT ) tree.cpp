#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int a[10000];
int BIT[10000];


void update(int i, int inc, int N) {
    while (i <= N) {
        BIT[i] += inc;
        i += (i & (-i));
    }
}

int query(int i) {
    int ans = 0;
    while (i > 0) {
        ans += BIT[i];
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
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << query(r) - query(l - 1) << endl;
        }
    }
}