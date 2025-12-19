int idx;
void helper(struct TreeNode * root, int * result){
    if(root == NULL) return;
    helper(root->left, result);
    result[idx++] = root->val;
    helper(root->right, result);
}


int getMinimumDifference(struct TreeNode* root) {
    idx = 0;
    int * result = malloc(sizeof(int)* 100000);
    helper(root, result);
    int min = INT_MAX;
    int i = 1;
    while(i < idx){
        printf("%d ", result[i]);
        min = fmin(result[i]-result[i-1], min);
        i++;
    }
    return min;
}