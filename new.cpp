#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mkp make_pair

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.S > p2.S;
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
    int t; cin >> t; while (t--)
    {
        // int b[] = {1, 2, 3, 4};
        int i, j, k, n, m, d, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        vector<pair<int, int>> a;
        for (int i = 0; i < n; ++i)
        {
            int dist, max_cap;
            cin >> dist >> max_cap;
            a.pb(mkp(dist, max_cap));
            // cout << a[i].F << "------" << endl;
        }
        int distance_to_cover, initial;
        cin >> distance_to_cover >> initial;

        sort(a.begin(), a.end(), compare);
        for (int i = 0; i < n; ++i) {
            a[i].F = distance_to_cover - a[i].F;
        }
        // for (auto x : a) {
        //     cout << x.F << "  " << x.S << endl;
        // }
        j = 0;
        d = 0;
        while (cnt < n && ans < distance_to_cover) {
            int act_dis = a[j].F - d;
            if (initial >= act_dis) {
                initial -= act_dis;
                d += act_dis;
                initial += a[j].S;
                ans = initial + d;
                sum++;
            }
            j++;
            cnt++;
        }
        cout << sum << endl;
        a.clear();


    }
}