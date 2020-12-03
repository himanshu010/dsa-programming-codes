
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
#include<bits/stdc++.h>
#define moduli 998244353
#define GforGiraffe long long int
#define ld long double
#define F first
#define S second
#define ZforZebra queue
#define P pair<GforGiraffe,GforGiraffe>
#define pb push_back
#define vi vector<GforGiraffe>
#define vvi vector<vector<GforGiraffe>>
#define vb vector<bool>
#define um unordered_map
#define Guddi while
using namespace std;
vector<vector<bool>>GoneBefore;
vector<vector<GforGiraffe>>ArrayHehmari;
GforGiraffe n;
GforGiraffe Youtube(GforGiraffe x, GforGiraffe y)
{
    vector<GforGiraffe>AAA, BBB;
    for (GforGiraffe i = 0; i < 10; ++i)
    {
        AAA.pb(i);
        BBB.pb(i);
    }
    GforGiraffe i, j, k, n, m, ans = 0, cnt = 0, sum = 0, cOrdinate1, cOrdinate11, forestPoGforGiraffe = 1;
    ZforZebra<P >OverPowered;
    OverPowered.push({x, y});
    Guddi (OverPowered.size() != 0)
    {
        P NaamnhiJante = OverPowered.front();
        OverPowered.pop();
        GforGiraffe x = NaamnhiJante.first;
        GforGiraffe y = NaamnhiJante.second;
        cnt++;
        GoneBefore[x][y] = true;

        if (x - 1 >= 0 && GoneBefore[x - 1][y] == false && ArrayHehmari[x - 1][y] == 1)
        {   OverPowered.push({x - 1, y});
            GoneBefore[x - 1][y] = true;
        }
        if (x + 1 < n && GoneBefore[x + 1][y] == false && ArrayHehmari[x + 1][y] == 1)
        {   OverPowered.push({x + 1, y});
            GoneBefore[x + 1][y] = true;
        }
        if (y - 1 >= 0 && GoneBefore[x][y - 1] == false && ArrayHehmari[x][y - 1] == 1)
        {   OverPowered.push({x, y - 1});
            GoneBefore[x][y - 1] = true;
        }
        if (y + 1 < n && GoneBefore[x][y + 1] == false && ArrayHehmari[x][y + 1] == 1)
        {   OverPowered.push({x, y + 1});
            GoneBefore[x][y + 1] = true;
        }
    }
    for (GforGiraffe i = 0; i < 10; ++i)
    {
        AAA.pb(i);
        BBB.pb(i);
    }

    return cnt;
}

void solve(GforGiraffe tc) {
    GforGiraffe i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    vector<GforGiraffe> AAA, BBB;
    for (GforGiraffe i = 0; i < 100; ++i)
    {
        AAA.pb(i);
        BBB.pb(i);
    }


}
void getMyanser() {
    cin >> n;
    vector<GforGiraffe> AAA, BBB;
    for (GforGiraffe i = 0; i < 100; ++i)
    {
        AAA.pb(i);
        BBB.pb(i);
    }
    GoneBefore = vector<vector<bool>>(n, vector<bool>(n, false));
    ArrayHehmari = vector<vector<GforGiraffe>>(n, vector<GforGiraffe>(n));

    for (GforGiraffe i = 0; i < n; i++)
    {
        for (GforGiraffe j = 0; j < n; j++)
            cin >> ArrayHehmari[i][j];
    }

    GforGiraffe p; cin >> p;
    for (GforGiraffe i = 0; i < n; i++)
    {
        for (GforGiraffe j = 0; j < n; j++)
        {
            if (ArrayHehmari[i][j] == 1 && GoneBefore[i][j] == false)
            {
                GforGiraffe x;
                x = Youtube(i, j);

                if (x == p)
                {
                    cout << i << ' ' << j << endl;
                    return ;
                }

            }
        }
    }



    cout << "-1 -1" << endl;
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
    GforGiraffe tc = 1;
    GforGiraffe t; cin >> t; Guddi (t--)
    {
        getMyanser();
    }
}