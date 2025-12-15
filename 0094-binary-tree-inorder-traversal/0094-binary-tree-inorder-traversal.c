int * result;
void helper(struct TreeNode * root, int *returnSize){
    if(root == NULL) return;
    helper(root->left, returnSize);
    result[(*returnSize)++] = root->val;
    helper(root->right, returnSize);
    return;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    result = malloc(sizeof(int) * 10000);
    *returnSize = 0;
    helper(root, returnSize);
    return result;
}