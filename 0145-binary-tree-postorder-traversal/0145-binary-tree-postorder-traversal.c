int idx;
int * result;

void helper(struct TreeNode * root){
    if(root == NULL) return;
    helper(root->left);
    helper(root->right);
    result[idx++] = root->val;
    return;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    result = malloc(sizeof(int) * 100000);
    idx = 0;
    helper(root);
    *returnSize = idx;
    return result;
}