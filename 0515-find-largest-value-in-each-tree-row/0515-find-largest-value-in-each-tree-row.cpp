
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        queue<TreeNode *> q;
        q.push(root);
        while( !q.empty()){
            int len = q.size();
            int max = INT_MIN;
            for(int i = 0; i < len; i++){
                TreeNode  * node = q.front();
                q.pop(); //ths func doesnt return front of q   ueue
                max = fmax(max, node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            result.push_back(max);
        }
        return result;
    }
};