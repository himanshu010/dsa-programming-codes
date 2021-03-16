/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.codes )               |
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
#define PQ priority_queue
using namespace std;

//---------------------------------------------------debugging-------------------------------------------------------------}
                                                                                                      \
    }
void print(int a)
{
    cout << a << endl;
}
void print(int a, int b)
{
    cout << a << " " << b << endl;
}
void print(int a, int b, int c)
{
    cout << a << " " << b << " " << c << endl;
}
void print(int a, int b, int c, int d)
{
    cout << a << " " << b << " " << c << " " << d << endl;
}
void print(int a, int b, int c, int d, int e)
{
    cout << a << " " << b << " " << c << " " << d << " " << e << endl;
}
void print(vector<int> a)
{
    for (auto i : a)
        cout << i << " ";
    cout << endl;
}
void print(string s)
{
    cout << s << endl;
}
void print(string s, int a)
{
    cout << s << " " << a;
    cout << endl;
}
void print(string s1, int a, string s2, int b)
{
    cout << s1 << " " << a << " " << s2 << " " << b;
    cout << endl;
}
void printline(int a)
{
    cout << "line " << a << endl;
}
//_________________________________________________________________________________________________________________________}

vvi graph;
vi visited_time, low_time, parent;
vb articulation;

int tt = 0;
void dfs(int cur, int par)
{
    parent[cur] = par;
    visited_time[cur] = low_time[cur] = tt;
    tt += 1;
    int cnt = 0;

    for (auto child : graph[cur])
    {
        if (visited_time[child] == -1)
        {
            cnt += 1;
            dfs(child, cur);
            low_time[cur] = min(low_time[cur], low_time[child]);
            if (parent[cur] == -1 and cnt > 1)
            {
                articulation[cur] = 1;
            }
            if (parent[cur] != -1 and visited_time[cur] <= low_time[child])
            {
                articulation[cur] = 1;
            }
        }

        else if (child != parent[cur])
        {
            low_time[cur] = min(low_time[cur], low_time[child]);
        }
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;

    graph.resize(n + 1);
    visited_time.resize(n + 1);
    low_time.resize(n + 1);
    articulation.resize(n + 1);
    parent.resize(n + 1);

    fill(visited_time.begin(), visited_time.end(), -1);
    fill(low_time.begin(), low_time.end(), INT_MAX);
    fill(articulation.begin(), articulation.end(), 0);

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;

        graph[l].pb(r);
        graph[r].pb(l);
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited_time[i] == -1)
        {
            dfs(i, -1);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (articulation[i])
        {
            cout << i << endl;
        }
    }
}
int32_t main()
{
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