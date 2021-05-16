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

class node
{
  public:
    char data;
    unordered_map<char, node *> children;
    bool terminal;
    node(char d)
    {
        data = d;
        terminal = 0;
    }
};

class trie
{
    node *root;
    int cnt;

  public:
    trie()
    {
        root = new node('\0');
        cnt = 0;
    }

    void insert(char *w)
    {
        node *temp = root;
        for (int i = 0; w[i] != '\0'; ++i)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                node *n = new node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }

        temp->terminal = true;
    }
    bool find(char *w)
    {
        node *temp = root;
        for (int i = 0; w[i] != '\0'; ++i)
        {
            char ch = w[i];
            if (temp->children.count(ch) == 0)
            {
                return false;
            }

            else
            {
                temp = temp->children[ch];
            }
        }

        return temp->terminal;
    }
};

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    trie t;
    char words[][10] = {"a", "hello", "not", "news", "apple"};

    char w[10];
    cin >> w;

    for (int i = 0; i < 5; ++i)
    {
        t.insert(words[i]);
    }

    if (t.find(w))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }
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
        int tc = 1;
        solve(tc);
        tc++;
    }
}