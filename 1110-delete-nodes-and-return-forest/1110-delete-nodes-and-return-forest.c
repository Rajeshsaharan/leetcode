struct TreeNode ** result;
int map[1002]; //according to constrains
int idx;
struct TreeNode *  helper(struct TreeNode * root){
    if(root == NULL) return NULL;
    root->left = helper(root->left);
    root->right = helper(root->right);
    if(map[root->val] == 1){
        if(root->left) result[idx++] = root->left;
        if(root->right) result[idx++] = root->right;
        return NULL;
    }
    return root;
}


struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize){
    result = malloc(sizeof(struct TreeNode *) * 100000);
    idx = 0;
    int i = 0;
    memset(map, 0, sizeof(map));
    while(i < to_deleteSize){
        map[to_delete[i]] = 1;
        i++;
    }
    helper(root);
    if(map[root->val] == 0) result[idx++] = root;
    *returnSize = idx;
    return result;

}