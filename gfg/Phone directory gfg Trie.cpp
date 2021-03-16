#include <bits/stdc++.h>
using namespace std;
vector<string> row;
class Node {
public:
    char data;
    unordered_map<char, Node*>mp;
    bool isTerminal;

    Node(char d) {
        this->data = d;
        isTerminal = 0;
    }
};

class Trie {
public:
    Node* root;
    vector<string> b;
    Trie(Node* root, vector<string> b) {
        this->root = root;
        this->b = b;
    }
    void insertNode(string s) {
        Node* temp = root;
        for (auto x : s) {
            if (temp->mp.count(x)) {
                temp = temp->mp[x];
            }
            else {
                temp->mp[x] = new Node(x);
                temp = temp->mp[x];
            }
        }
        temp->isTerminal = 1;
    }

    void printNode(string a) {
        row.push_back(a.substr(1));
    }

    void getNode(Node* temp, string a, int i, string aaa) {
        // cout<<temp->data<<' '<<a<<' '<<endl;
        if (i < a.size()) {
            if (temp->mp.count(a[i])) {
                getNode(temp->mp[a[i]], a, i + 1, aaa + temp->data);
            }
        }
        else {
            if (temp->isTerminal) {
                printNode(aaa + temp->data);
            }
            for (auto x : temp-> mp) {
                getNode(temp->mp[x.first], a, i + 1, aaa + temp->data);
            }
        }
    }


};


int main() {
    int t; cin >> t; while (t--) {
        Node* root = new Node('$');
        int n; cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Trie* t = new Trie(root, a);

        for (auto x : a) {
            t->insertNode(x);
        }

        string s;
        cin >> s;
        n = s.size();
        for (int i = 1; i <= n; i++) {
            row.clear();
            t->getNode(root, s.substr(0, i), 0, "");
            if (row.size() == 0) {
                cout << 0;
            }
            sort(row.begin(), row.end());
            for (auto x : row) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
}