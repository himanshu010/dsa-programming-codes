/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|                       (himanshu010)                       |
|                                                           |
|                                                           |
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
#define R return

using namespace std;

vector<vector<P>> graph(100005);
void addEdge(int u, int v, int dist) {
    graph[u].pb({v, dist});
}

void printAdj(int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << i << "---->";
        for (auto k : graph[i]) {
            cout << "(" << k.F << ", " << k.S << "), ";
        }
        cout << endl;
    }
}

void dijkstra(int src, int n) {
    unordered_map<int, int> dist;

    //Set all distances to infinity;
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INT_MAX;
    }

    //Make a set to find out node with the minimum distance
    set<pair<int, int>> s;
    dist[src] = 0;
    s.insert({0, src});
    while (!s.empty()) {
        //Find the pair at the front

        auto p = *(s.begin());
        int node = p.S;
        int nodeDistance = p.F;
        s.erase(s.begin());

        //Iterate over the neighbour of the current node
        for (auto childPair : graph[node]) {
            if (nodeDistance + childPair.S < dist[childPair.F]) {


                //In the set, updation is not possible,
                //then we have to remove the old pair and insert the new pair
                int dest = childPair.F;
                auto f = s.find({dist[dest], dest});
                if (f != s.end()) {
                    s.erase(f);
                }

                //Insert the new pair
                dist[dest] = nodeDistance + childPair.S;
                s.insert({dist[dest], dest});
            }
        }
    }
    //print distance
    for (auto d : dist) {
        cout << d.F << " is located at " << d.S << endl;
    }
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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int temp, temp1;
            int temp2;
            cin >> temp >> temp1 >> temp2;
            addEdge(temp, temp1, temp2);
        }
        // g.printAdj();
        dijkstra(1, n);

        printAdj(n);




    }
}