/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
  public:
    pair<TreeNode *, int> build(int s, int e, int i, vector<int> &inorder, vector<int> &postorder)
    {
        if (s > e)
        {
            return {NULL, i + 1};
        }
        if (s == e)
        {
            TreeNode *c = new TreeNode(inorder[s]);
            return {c, i};
        }
        TreeNode *root = new TreeNode(postorder[i]);
        int cur = find(inorder.begin(), inorder.end(), postorder[i]) - inorder.begin();

        pair<TreeNode *, int> r = build(cur + 1, e, i - 1, inorder, postorder);
        pair<TreeNode *, int> l = build(s, cur - 1, r.second - 1, inorder, postorder);
        root->left = l.first;
        root->right = r.first;
        return {root, min({i, r.second, l.second})};
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return build(0, inorder.size() - 1, inorder.size() - 1, inorder, postorder).first;
    }
};