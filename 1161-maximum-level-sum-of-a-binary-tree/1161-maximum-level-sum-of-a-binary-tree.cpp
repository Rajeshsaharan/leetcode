
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode *> q;
        q.push(root);
        pair<int , int> result;
        int j = 1;
        int max = INT_MIN;
        while( !q.empty()){
            int len = q.size();
            int sum = 0;
            for(int i = 0; i < len; i++){
                TreeNode  * node = q.front();
                q.pop(); //ths func doesnt return front of q   ueue
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            if(sum > max){
                max = sum;
                result  = make_pair(max,j);
            }
            j++;
        }
        return result.second; 
    }
};