int idx;
int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void helper(struct TreeNode * root, int * result){
    if(root == NULL) return;
    result[idx++] = root->val;
    helper(root->left, result);
    helper(root->right, result);
}

int kthSmallest(struct TreeNode* root, int k) {
    idx = 0;
    int * result = malloc(sizeof(int)* 100000);
    helper(root, result);
    qsort(result, idx, sizeof(result[0]), comp);
    return result[k-1];
}