int mx = INT_MIN;
int findDiameter(Node *root) {

    if (root->left == NULL and root->right == NULL) {
        return 1;
    }

    int l = 0, r = 0;
    if (root->left) {
        l = findDiameter(root->left);
    }
    if (root->right) {
        r = findDiameter(root->right);
    }
    mx = max(mx, l + r + 1);
    return max(l, r) + 1;
}
int diameter(Node* root) {
    // Your code here
    mx = INT_MIN;

    mx = max(mx, findDiameter(root));
    return mx;
}