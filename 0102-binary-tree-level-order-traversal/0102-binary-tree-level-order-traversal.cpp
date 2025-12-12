class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> result;
       if(!root) return result;
       queue<TreeNode *> q;
       q.push(root);
       while(!q.empty()){
        int len = q.size();
        vector<int> current_level;
        int i = 0;
        while(i < len){
            TreeNode * root = q.front();
            q.pop();
            current_level.push_back(root->val);
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            ++i;
        }
        result.push_back(current_level);
       }
        return result;
    }
};