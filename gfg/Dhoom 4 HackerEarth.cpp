/*
*-----------------------------------------------------------*
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.com )                 |
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
using namespace std;
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    int target;
    cin >> m >> target >> n;
    set<int> a;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        a.insert(temp);
    }

    vector<int> visited(100001, -1);
    visited[m] = 0;

    queue<int> qu;
    qu.push(m);
    while (!qu.empty())
    {
        int cur = qu.front();
        if (cur == target)
        {
            cout << visited[cur] << endl;
            return;
        }
        qu.pop();
        for (auto x : a)
        {
            int mul = (x * cur) % 100000;
            if (visited[mul] == -1)
            {
                qu.push(mul);
                visited[mul] = visited[cur] + 1;
            }
        }
    }
    cout << visited[target] << endl;
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
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}