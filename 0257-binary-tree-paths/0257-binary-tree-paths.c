

char** result;
void helper(struct TreeNode* root, char* buf, int bs, int* returnSize) {
    if (root == NULL)
        return;
    if (root->val < -9 || root->val > 9) {
        if (root->val < -9)
            buf[bs++] = '-';

        int n = abs(root->val);
        int i = 0;
        char local[3]; // according to constrains
        while (n > 0) {
            local[i] = (n % 10) + '0';
            n /= 10;
            i++;
        }
        i--;
        while(i >= 0){
            buf[bs++] = local[i];
            i--;
        }
        

    } else {
        if(root->val < 0) buf[bs++] = '-';
        buf[bs++] = abs(root->val) + '0';
    }
    if (root->left == NULL && root->right == NULL) {
        buf[bs] = '\0';
        result[*returnSize] = malloc(sizeof(char) * (bs + 1));
        int i = 0;
        while (buf[i] != '\0') {
            result[*returnSize][i] = buf[i];
            i++;
        }
        result[*returnSize][i] = '\0';
        (*returnSize)++;
        return;
    }
    buf[bs++] = '-';
    buf[bs++] = '>';
    helper(root->left, buf, bs, returnSize);
    helper(root->right, buf, bs, returnSize);
    return;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    result = malloc(sizeof(*result) * 10000);
    char* buf = malloc(sizeof(char) * 10000);
    *returnSize = 0;
    int bs = 0;
    helper(root, buf, bs, returnSize);
    return result;
}