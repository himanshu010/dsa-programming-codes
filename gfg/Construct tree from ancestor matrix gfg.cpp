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
#define PQ priority_queue
using namespace std;

class Node
{

  public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node *temp)
{
    if (!temp)
    {
        return;
    }
    inOrder(temp->left);
    cout << temp->data << ' ';
    inOrder(temp->right);
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<vector<bool>> a(n, vector<bool>(n));
    multimap<int, int> mp;
    vector<Node *> address(n);
    for (int i = 0; i < n; ++i)
    {
        address[i] = new Node(i);
    }

    for (int i = 0; i < n; ++i)
    {
        cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            bool temp;
            cin >> temp;

            a[i][j] = temp;
            if (a[i][j])
            {
                cnt += 1;
            }
        }

        mp.insert({cnt, i});
    }

    for (auto x : mp)
    {
        if (x.S != 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[x.S][i])
                {

                    Node *temp = address[i];
                    Node *par = address[x.S];
                    if (par->left != temp and par->right != temp)
                    {
                        if (!(par->left))
                        {
                            par->left = temp;
                        }
                        else
                        {
                            par->right = temp;
                        }
                        address[i] = par;
                    }
                }
            }
        }
    }

    auto it = mp.end();
    it--;
    pair<int, int> tt = *it;
    Node *root = address[tt.S];
    inOrder(root);
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