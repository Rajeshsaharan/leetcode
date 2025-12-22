int max = 0;
int helper(struct TreeNode *root){
    if(root == NULL) return 0;
    int l = helper(root->left);
    int r = helper(root->right);
    int left_path = 0;
    int right_path = 0;
    if(root->left && root->left->val == root->val)
        left_path = l + 1;

    if(root->right && root->right->val == root->val)
        right_path = r + 1;

    max = fmax(max, left_path + right_path);
    return fmax(left_path, right_path);
}

int longestUnivaluePath(struct TreeNode* root) {
    max = 0;
    helper(root);
    return max;
}
