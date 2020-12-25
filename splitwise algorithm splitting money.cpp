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

#include <bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define R return

using namespace std;

void solve()
{
    int i, j, k, n, ans = 0, cnt = 0, sum = 0;
    int no_of_transactions, friends;
    cin >> no_of_transactions >> friends;

    int x, y, amount;

    int net[100000] = {0};

    while (no_of_transactions--)
    {
        cin >> x >> y >> amount;
        net[x] -= amount;
        net[y] += amount;
    }

    multiset<P> m;

    for (int i = 0; i < friends; ++i)
    {
        if (net[i] != 0)
        {
            m.insert(make_pair(net[i], i));
        }
    }

    cnt = 0;
    // Pop Out two person from left and right and try to settle them
    while (!m.empty())
    {
        auto low = m.begin();
        auto high = prev(m.end());
        P debit = *low;

        int debit_amount = debit.F;
        int debiter = debit.S;

        P credit = *high;

        int credit_amount = credit.F;
        int crediter = credit.S;

        // Erase
        m.erase(low);
        m.erase(high);

        int settlement_amount = min(-debit_amount, credit_amount);

        // Settle amount from debiter to accepter

        debit_amount += settlement_amount;
        credit_amount -= settlement_amount;

        cout << debiter << " will give " << crediter << ": " << settlement_amount << endl;

        if (credit_amount != 0)
        {
            m.insert({credit_amount, crediter});
        }
        if (debit_amount != 0)
        {
            m.insert({debit_amount, debiter});
        }
        cnt++;
    }

    cout << cnt << endl;
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
    // int t;cin>>t;while(t--)
    {
        solve();
    }
}