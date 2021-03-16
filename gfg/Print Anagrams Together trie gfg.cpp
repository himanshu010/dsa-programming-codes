vector<vector<string>> ans;
vector<string> aaa;

class Node {
public:
    char data;
    unordered_map<char, Node*>mp;
    vector<int> isTerminated;


    Node(char d) {
        this->data = d;
    }
};

class Trie {
public:
    Node* root;
    vector<string> str;
    Trie(Node* root, vector<string>str) {
        this->root = root;
        this->str = str;
    }

    void insertNode(string a, int i) {
        Node* temp = root;
        for (auto x : a) {
            if (temp->mp.count(x)) {
                temp = temp->mp[x];
            }
            else {
                temp->mp[x] = new Node(x);
                temp = temp->mp[x];
            }
        }
        temp->isTerminated.push_back(i);
    }
    void addNodes(vector<int> a) {
        aaa.clear();
        for (auto x : a) {
            aaa.push_back(str[x]);
        }
        ans.push_back(aaa);
    }
    void getNode(Node* temp) {
        if (temp->isTerminated.size() >= 1) {
            addNodes(temp->isTerminated);
        }
        for (auto x : temp->mp) {
            getNode(temp->mp[x.first]);
        }
    }
};

vector<vector<string> > Anagrams(vector<string>& string_list)
{
    ans.clear();
    Node* root = new Node('$');
    Trie* t = new Trie(root, string_list);
    int cnt = 0;
    for (auto x : string_list) {
        sort(x.begin(), x.end());
        t->insertNode(x, cnt);
        cnt += 1;
    }
    t->getNode(root);
    return ans;
}