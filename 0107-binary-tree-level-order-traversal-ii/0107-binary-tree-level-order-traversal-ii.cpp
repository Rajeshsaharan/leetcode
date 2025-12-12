class Solution {
private:
    void dfs(TreeNode * root,int level, vector<int> &v){
        if(root == NULL) return;
        if(level == 1){
            v.push_back(root->val);
        }else{
            dfs(root->left, level-1, v);
            dfs(root->right, level-1, v);
        }
    }
private:
    int _height(TreeNode * root){
        if(root == NULL) return 0;
        int left_height = _height(root->left);
        int right_height = _height(root->right);
        return fmax(left_height, right_height) +1;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<vector<int>> result;
       int height = _height(root);
       for(int i = height; i >= 1 ; i--){
            vector<int> v;
            dfs(root, i,v);
            result.push_back(v);
       } 
    return result;
    }
};