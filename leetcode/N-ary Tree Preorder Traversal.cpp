/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

vector<int> ans;

void preOrder(Node *cur)
{
    ans.push_back(cur->val);

    for (auto x : cur->children)
    {
        preOrder(x);
    }
}

class Solution
{
  public:
    vector<int> preorder(Node *root)
    {
        ans.clear();
        if (root == NULL)
        {
            return ans;
        }
        preOrder(root);
        return ans;
    }
};