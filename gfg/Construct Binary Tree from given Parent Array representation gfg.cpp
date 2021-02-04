Node *createTree(int parent[], int n)
{
    vector<Node *> address(n);
    for (int i = 0; i < n; i++)
    {
        address[i] = new Node(i);
    }
    Node *root;

    for (int i = 0; i < n; i++)
    {
        int pp = parent[i];
        if (pp != -1)
        {
            if (!address[pp]->left)
            {
                address[pp]->left = address[i];
            }
            else
            {
                address[pp]->right = address[i];
            }
        }
        else
        {
            root = address[i];
        }
    }

    return root;
}