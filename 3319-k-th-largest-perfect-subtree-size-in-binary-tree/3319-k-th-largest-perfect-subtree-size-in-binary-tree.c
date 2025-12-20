struct my_struct {
    int height;
    int size;
};


int idx;
int * result;

int comp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

struct my_struct *  helper(struct TreeNode * root){
    if(root == NULL){
        struct my_struct * st = malloc(sizeof(struct my_struct));
        st->height = 0;
        st->size = 0;
        return st;
    }
    struct my_struct * left = helper(root->left);
    struct my_struct * right = helper(root->right);
    struct my_struct * st = malloc(sizeof(struct my_struct));
    st->height = 1 + fmax(left->height, right->height);
    st->size = 1 + left->size + right->size;
    int perfect_binary_tree_node = (1<< st->height) -1;
    if(st->size == perfect_binary_tree_node){
        result[idx++] = st->size;
    }
    return st; 
    
}


int kthLargestPerfectSubtree(struct TreeNode* root, int k) {
    idx = 0;
    result  = calloc(100000, sizeof(int));
    helper(root);
    qsort(result, idx, sizeof(result[0]) , comp);
    return result[k-1] != 0 ? result[k-1] : -1 ;
}