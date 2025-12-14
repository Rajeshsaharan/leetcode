void flatten(struct TreeNode* root) {
   if(root == NULL) return;
   flatten(root->left);
   flatten(root->right);

   if(root->left != NULL){
    struct TreeNode * temp = root->left;
    while(temp->right) temp = temp->right;
    temp->right = root->right;
    root->right = root->left;
    root->left = NULL;
   }
}