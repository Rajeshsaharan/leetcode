char ** result;
int idx;

int compare_strings(const void *p1, const void *p2) {

    return strcmp(*(const char **)p1, *(const char **)p2);
}

void helper(struct TreeNode * root, char * buf, int bs){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        buf[bs++] = root->val + 97;
        buf[bs] = '\0';
        result[idx] = malloc(sizeof(char) *(bs+1));
        int i =0;
        while(i < bs){
            result[idx][bs-i-1] = buf[i];
            i++;
        }
        result[idx][i] = '\0';
        idx++;
        return;
    }
    buf[bs] = root->val + 97;
    helper(root->left, buf, bs+1);
    helper(root->right, buf,  bs+1);
}



char* smallestFromLeaf(struct TreeNode* root) {
    idx = 0;
    result = malloc(sizeof(char*)  *100000);
    char * buf = malloc(sizeof(char) * 10000);
    int bs = 0;
    helper(root, buf, bs);
    qsort(result, idx, sizeof(result[0]), compare_strings);
    return result[0];
    
}