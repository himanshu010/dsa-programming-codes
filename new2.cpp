#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> arr[1000];

void dfs(int u, vector<ll> &disc, vector<ll> &low, vector<ll> &parent, vector<bool> &arti)

{

    static ll time = 0;

    disc[u] = low[u] = time;

    time++;

    int children = 0;

    for (int i = 0; i < arr[u].size(); i++)

    {

        ll v = arr[u][i];

        if (disc[v] == -1)

        {

            children++;

            parent[v] = u;

            dfs(v, disc, low, parent, arti);

            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && children > 1)

                arti[u] = true;

            if (parent[u] != -1 && low[v] >= disc[u])

                arti[u] = true;
        }

        else if (v != parent[u])

            low[u] = min(low[u], disc[v]);
    }
}

int main()

{

    ll n, m, q;
    cin >> n >> m;

    while (m--)

    {

        ll a, b;
        cin >> a >> b;

        arr[a].push_back(b);

        arr[b].push_back(a);
    }

    vector<ll> disc(n + 1, -1);

    vector<ll> low(n + 1, -1);

    vector<ll> parent(n + 1, -1);

    vector<bool> arti(n + 1, false);

    for (int i = 1; i <= n; i++)

    {

        if (disc[i] == -1)

        {

            dfs(i, disc, low, parent, arti);
        }
    }
    cin >> q;
    while (q--)

    {

        ll ans;
        cin >> ans;

        if (arti[ans])

            cout << "Satisfied"
                 << " " << arr[ans].size() << endl;

        else

            cout << "Not Satisfied" << endl;
    }
}