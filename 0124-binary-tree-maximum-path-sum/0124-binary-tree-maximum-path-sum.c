int max;
int helper(struct TreeNode * root){
    if(root == NULL) return 0;
    int l= helper(root->left);
    int r = helper(root->right);
    int converge = l + r + root->val;
    int left_or_right = fmax(l,r) + root->val;
    int root_value = root->val;
    int max_valid = fmax(fmax(converge, left_or_right), root_value);
    max = fmax(max, max_valid);
    return fmax(left_or_right, root->val);
}
int maxPathSum(struct TreeNode* root) {
    max = INT_MIN;
    helper(root);
    return max;
}