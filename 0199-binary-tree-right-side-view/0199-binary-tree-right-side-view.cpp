
class Solution {
private:
    void dfs(TreeNode * root , vector<vector<int>> &v, int level){
        if(root == NULL) return;
        v[level].push_back(root->val);
        dfs(root->left, v, level +1);
        dfs(root->right, v, level +1);
    }
private:
    int height(TreeNode * root){
        if(root== NULL) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        return 1 +max(left_height, right_height);
    }
public:
        vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> result;
        //pre compute value;
        int h = height(root);
        for(int i = 0; i< h; i++){
            result.push_back({});
        }
        dfs(root, result, 0);
        vector<int> result2;
        for(int i = 0; i< h; i++){
            result2.push_back(result[i][result[i].size()-1]);
        }
        return result2;
    }
};