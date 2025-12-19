int is_balanced;
int helper(struct TreeNode * root){
    if(root == NULL) return 0;
    int left_height = 1 + helper(root->left);
    int right_height = 1 +helper(root->right);
    if(abs(left_height-right_height) >1){
        is_balanced  = 0;
    }
    return fmax(right_height, left_height);
}

bool isBalanced(struct TreeNode* root) {
    is_balanced = 1;
    helper(root);
    return is_balanced;
}