int root_index;
int inorder_hash[6002];

struct TreeNode * helper(int * preorder, int in_start, int in_end){
    if(in_start >in_end) return NULL;
    int root_val = preorder[root_index++];
    int mid = inorder_hash[root_val + 3000];
    struct TreeNode * root = malloc(sizeof(struct TreeNode));
    root->val = root_val;
    root->left = helper(preorder, in_start, mid-1);
    root->right = helper(preorder, mid+1, in_end);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    root_index = 0;
    int i = 0;
    while(i < inorderSize){
        inorder_hash[inorder[i]+3000] = i; // accroding to constrians preordre[i] and inorder[i] are unique;
        i++;
    }
    return helper(preorder, 0, inorderSize -1);
}