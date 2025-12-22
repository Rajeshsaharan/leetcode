int max_diameter;

int height(struct TreeNode* root) {
    if (root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    max_diameter = fmax(max_diameter, l + r);
    return fmax(l, r) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    max_diameter = INT_MIN;
    height(root);
    return max_diameter;
}