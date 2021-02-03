void printVertically(Node* root, map<int, vector<int>>&mp) {
    queue<pair<Node*, int>> qu;
    qu.push({root, 0});
    while (!qu.empty()) {
        pair<Node*, int> cur = qu.front();
        mp[cur.second].push_back(cur.first->data);
        qu.pop();
        if (cur.first->left) {
            qu.push({cur.first->left, cur.second - 1});
        }
        if (cur.first->right) {
            qu.push({cur.first->right, cur.second + 1});
        }
    }
}
vector<int> verticalOrder(Node *root)
{
    map<int, vector<int>>mp;
    printVertically(root, mp);
    vector<int> ans;
    for (auto x : mp) {
        for (auto y : x.second) {
            ans.push_back(y);
        }
    }

    return ans;
}