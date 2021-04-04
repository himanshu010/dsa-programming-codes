class Solution
{
  public:
    bool ans = 1;
    int check(Node *root)
    {
        if (!root->left and !root->right)
        {
            return root->data;
        }
        int l = INT_MIN;
        int r = INT_MIN;
        if (root->left)
        {
            l = check(root->left);
        }
        if (root->right)
        {
            r = check(root->right);
        }

        int l1 = l, r1 = r;
        if (r1 == INT_MIN)
        {
            r1 = INT_MAX;
        }

        if (l1 >= root->data or r1 <= root->data)
        {
            ans = 0;
            return 0;
        }

        return max(l, r);
    }
    bool isBST(Node *root)
    {
        ans = 1;
        check(root);
        return ans;
    }
};