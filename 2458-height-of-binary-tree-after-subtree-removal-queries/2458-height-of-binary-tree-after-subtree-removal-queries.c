
int hash_map[100001][2];       // [node_val][0]=height, [1]=level
int level_hash_map[100001][2]; // [level][0]=max, [1]=second max
int max_level = 0;
int height(struct TreeNode *root, int level) {
    if (root == NULL) return 0;
    if (level > max_level) max_level = level;
    int lh = height(root->left,  level + 1);
    int rh = height(root->right, level + 1);
    int h = 1 + (lh > rh ? lh : rh);
    hash_map[root->val][0] = h;
    hash_map[root->val][1] = level;
    if (h > level_hash_map[level][0]) {
        level_hash_map[level][1] = level_hash_map[level][0];
        level_hash_map[level][0] = h;
    } else if (h > level_hash_map[level][1]) {
        level_hash_map[level][1] = h;
    }

    return h;
}

int* treeQueries(struct TreeNode* root,
                 int* queries,
                 int queriesSize,
                 int* returnSize) {

    memset(hash_map, 0, sizeof(hash_map));
    memset(level_hash_map, 0, sizeof(level_hash_map));
    max_level = 0;
    int total_height = height(root, 0);
    assert(hash_map[root->val][1] == 0);
    int *ans = malloc(sizeof(int) * queriesSize);

    for (int i = 0; i < queriesSize; i++) {
        int node = queries[i];
        int node_height = hash_map[node][0];
        int node_level  = hash_map[node][1];

        int best = level_hash_map[node_level][0];
        int second = level_hash_map[node_level][1];
        int use_height = (node_height == best) ? second : best;
        ans[i] = node_level + use_height - 1;
        if (ans[i] < 0) ans[i] = 0;
    }

    *returnSize = queriesSize;
    return ans;
}
