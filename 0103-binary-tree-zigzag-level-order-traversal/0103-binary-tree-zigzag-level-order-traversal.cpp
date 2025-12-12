

class Solution {
private:
    int height(TreeNode * root){
        if(root == NULL) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        return max(left_height, right_height) +1;
}
private:
    void dfs(TreeNode * root , vector<vector<int>> &v, int level , bool left_to_right){
        if(root == NULL) return;
        if(left_to_right){
            v[level].push_back(root->val);
        }else{
            v[level].insert(v[level].begin(), root->val); 
        }
        dfs(root->left, v, level +1, !left_to_right);
        dfs(root->right, v, level +1, !left_to_right);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int h = height(root);
        int i = 0;
        while(i < h){
            result.push_back({});
            i++;
        }
        dfs(root, result, 0, true);
        return result;
    }
};