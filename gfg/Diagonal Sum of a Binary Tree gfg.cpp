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
#define PQ priority_queue
#define input(a)    for(auto &i:a)  cin>>i;
using namespace std;

//---------------------------------------------------debugging-------------------------------------------------------------}
void print(int a)                              {    cout << a << endl;                                                     }
void print(int a, int b)                       {    cout << a << " " << b << endl;                                         }
void print(int a, int b, int c)                {    cout << a << " " << b << " " << c << endl;                             }
void print(int a, int b, int c, int d)         {    cout << a << " " << b << " " << c << " " << d << endl;                 }
void print(int a, int b, int c, int d, int e)  {    cout << a << " " << b << " " << c << " " << d << " " << e << endl;     }
void print(vector<int> a)                      {    for (auto i : a)    cout << i << " ";   cout << endl;                  }
void print(string s)                           {    cout << s << endl;                                                     }
void print(string s, int a)                    {    cout << s << " " << a; cout << endl;                                   }
void print(string s1, int a, string s2, int b) {    cout << s1 << " " << a << " " << s2 << " " << b; cout << endl;         }
void printline(int a)                          {    cout << "line " << a << endl;                                          }
//_________________________________________________________________________________________________________________________}


class Node {
public:
    int data;
    Node *left, *right;
    Node(int d) {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

map<int, vector<int>> mp;
void diagonalSum(Node* temp, int i) {
    mp[i].push_back(temp->data);
    if (temp->left) {
        diagonalSum(temp->left, i - 1);
    }
    if (temp->right) {
        diagonalSum(temp->right, i);
    }
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(6);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->right = new Node(7);
    root->right->left->left = new Node(12);
    root->left->right->left = new Node(11);
    root->left->left->right = new Node(10);

    diagonalSum(root, 0);
    for (auto x : mp) {
        sum = 0;
        for (auto y : x.second) {
            sum += y;
        }
        cout << sum << endl;
    }
}
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}