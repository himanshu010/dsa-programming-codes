class Solution
{
  public:
    Node *makeMirror(Node *temp)
    {
        Node *left = NULL;
        Node *right = NULL;
        if (temp->left)
        {
            left = makeMirror(temp->left);
        }
        if (temp->right)
        {
            right = makeMirror(temp->right);
        }

        temp->left = right;
        temp->right = left;

        return temp;
    }
    void mirror(Node *node)
    {
        makeMirror(node);
    }
};