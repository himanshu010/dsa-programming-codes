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
#define PQ priority_queue

using namespace std;

class Node
{
  public:
    char data;
    int isTerminal = 0;
    map<char, Node *> mp;

    Node(char data)
    {
        this->data = data;
        isTerminal = 0;
    }
};

class Trie
{
  public:
    Node *root;
    Trie(Node *root)
    {
        this->root = root;
    }

    void insertNode(string a)
    {
        Node *temp = root;
        for (auto x : a)
        {
            if (temp->mp.count(x))
            {
                temp = temp->mp[x];
            }
            else
            {
                temp->mp.insert({x, new Node(x)});
                temp = temp->mp[x];
            }
        }
        temp->isTerminal += 1;
    }
    void printNode(string ans)
    {
        print(ans);
    }

    void getNode(Node *temp, string ans)
    {
        if (temp->isTerminal)
        {
            while (temp->isTerminal--)
            {
                printNode(ans + temp->data);
            }
        }

        for (auto x : temp->mp)
        {
            if (temp == root)
            {
                getNode(temp->mp[x.F], ans);
            }
            else
            {
                getNode(temp->mp[x.F], ans + temp->data);
            }
        }
    }
};

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<string> a(n);
    input(a);
    Node *root = new Node('$');
    Trie *t = new Trie(root);
    for (auto x : a)
    {
        t->insertNode(x);
    }

    t->getNode(root, "");
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