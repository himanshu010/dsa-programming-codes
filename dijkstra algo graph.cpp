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

template<typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> m;
public:
    // Graph();
    void addEdge(T u, T v, int dist, bool bidir = true) {
        m[u].push_back(make_pair(v, dist));
        if (bidir) {
            m[v].pb(make_pair(u, dist));
        }
    }
    void printAdj() {
        for (auto j : m) {
            cout << j.F << "---->";
            for (auto k : j.S) {
                cout << "(" << k.F << ", " << k.S << "), ";
            }
            cout << endl;
        }
    }

    void dijkstra(T src) {
        unordered_map<T, int> dist;

        //Set all distances to infinity;

        for (auto j : m) {
            dist[j.F] = INT_MAX;
        }

        //Make a set to find out node with the minimum distance
        set<pair<int, T>> s;
        dist[src] = 0;
        s.insert(make_pair(0, src));
        while (!s.empty()) {
            //Find the pair at the front

            auto p = *(s.begin());
            T node = p.S;
            int nodeDistance = p.F;
            s.erase(s.begin());

            //Iterate over the neighbour of the current node
            for (auto childPair : m[node]) {
                if (nodeDistance + childPair.S < dist[childPair.F]) {


                    //In the set, updation is not possible,
                    //then we have to remove the old pair and insert the new pair
                    T dest = childPair.F;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if (f != s.end()) {
                        s.erase(f);
                    }

                    //Insert the new pair
                    dist[dest] = nodeDistance + childPair.S;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        //print distance
        for (auto d : dist) {
            cout << d.F << " is located at " << d.S << endl;
        }
    }

};


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
        Graph<string> g;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            string temp, temp1;
            int temp2;
            cin >> temp >> temp1 >> temp2;
            g.addEdge(temp, temp1, temp2);
        }
        // g.printAdj();
        g.dijkstra("Amritsar");




    }
}