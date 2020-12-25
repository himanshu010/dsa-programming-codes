#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define mkp make_pair

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, ans = 0, cnt = 0, sum = 0;
        map<string, int> m;
        // 1.Insert
        m.insert(mkp("mango", 100));

        // or
        pair<string, int> p;
        p.F = "apple";
        p.S = 120;
        m.insert(p);

        // or
        m["banana"] = 20;

        // 2. Search
        string fruit;
        cin >> fruit;

        auto it = m.find(fruit);
        if (it != m.end())
        {
            cout << m[fruit] << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }

        // or

        if (m.count(fruit))
        {
            cout << m[fruit] << endl;
        }
        else
        {
            cout << "not found" << endl;
        }

        // 3. Erase
        m.erase(fruit);
    }
}