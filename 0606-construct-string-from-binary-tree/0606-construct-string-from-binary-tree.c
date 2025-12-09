/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[100000]; // Buffer large enough for constraints (10^4 nodes)
int idx;

void dfs(struct TreeNode* t) {
    if (!t) return;
    
    // Write current node value
    idx += sprintf(buf + idx, "%d", t->val);
    
    // If left exists OR right exists (need to preserve empty left for right)
    if (t->left || t->right) {
        buf[idx++] = '(';
        dfs(t->left);
        buf[idx++] = ')';
        
        if (t->right) {
            buf[idx++] = '(';
            dfs(t->right);
            buf[idx++] = ')';
        }
    }
}

char* tree2str(struct TreeNode* root) {
    idx = 0;
    dfs(root);
    buf[idx] = '\0';
    return strdup(buf); 
}