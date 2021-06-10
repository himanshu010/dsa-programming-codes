class Solution
{
  public:
    int sum = 0;
    string tillNow;
    void findDigitNumber(TreeNode *cur)
    {
        if (!cur->left and !cur->right)
        {
            sum += stoi(tillNow);
        }

        if (cur->left)
        {
            tillNow += (char)(cur->left->val + '0');
            findDigitNumber(cur->left);
            tillNow = tillNow.substr(0, tillNow.size() - 1);
        }

        if (cur->right)
        {
            tillNow += (char)(cur->right->val + '0');
            findDigitNumber(cur->right);
            tillNow = tillNow.substr(0, tillNow.size() - 1);
        }
    }

    int sumNumbers(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        tillNow += (char)(root->val + '0');
        findDigitNumber(root);
        return sum;
    }
};