void storeDiagonally(Node* root, int cnt,  map<int, vector<int>>&mp) {
    mp[cnt].push_back(root->data);

    if (root->left) {
        storeDiagonally(root->left, cnt + 1, mp);
    }
    if (root->right) {
        storeDiagonally(root->right, cnt, mp);
    }
}


vector<int> diagonal(Node *root)
{
    vector<int> ans;
    map<int, vector<int>>mp;
    storeDiagonally(root, 0, mp);

    for (auto x : mp) {
        for (auto y : x.second) {
            ans.push_back(y);
        }
    }
    return ans;
}