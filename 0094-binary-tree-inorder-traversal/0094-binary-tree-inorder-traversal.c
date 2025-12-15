int * result;
void helper(struct TreeNode * root, int *bs){
    if(root == NULL) return;
    helper(root->left, bs);
    result[(*bs)++] = root->val;
    helper(root->right, bs);
    return;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    result = malloc(sizeof(int) * 10000);
    int bs = 0;
    helper(root, &bs);
    *returnSize = bs;
    return result;
}