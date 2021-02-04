int ans = 0;

int cntSubtree(Node *root, int n)
{

    if (!root->left and !root->right)
    {
        if ((root->data) == n)
        {
            ans += 1;
        }
        return (root->data);
    }
    int l = 0, r = 0;
    if (root->left)
    {
        l = cntSubtree(root->left, n);
    }
    if (root->right)
    {
        r = cntSubtree(root->right, n);
    }

    int sum = l + r + (root->data);
    if (sum == n)
    {
        ans += 1;
    }
    return sum;
}

int countSubtreesWithSumX(Node *root, int X)
{
    ans = 0;
    cntSubtree(root, X);
    return ans;
}