
class Solution {
private:
    int height(TreeNode * root){
        if(root == NULL) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        return max(left_height, right_height) +1;
    }
private:
    void dfs(TreeNode * root, vector<vector<int>> &v, int level){
        if(root ==NULL) return;
        v[v.size()-level-1].push_back(root->val);
        dfs(root->left, v, level+1);
        dfs(root->right,v, level +1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        //pre_intilze v[i]
        int h = height(root);
        int i = 0;
        while(i < h){
            result.push_back({}); // v is already an size of h; and i to <h intilized;
            i++;
        }
        dfs(root, result, 0);
    return result;
    }
};