#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define mkp make_pair
#define pb push_back

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.S < p2.S;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        vector<pair<int, int>> v;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int s, e;
            cin >> s >> e;
            v.pb(mkp(s, e));
        }

        sort(v.begin(), v.end(), compare);
        int res = 1;
        int fin = v[0].second;
        for (int i = 1; i < n; i++)
        {
            if ((v[i].F) >= fin)
            {
                fin = v[i].S;
                res++;
            }
        }
        cout << res << endl;
        v.clear();
    }
}