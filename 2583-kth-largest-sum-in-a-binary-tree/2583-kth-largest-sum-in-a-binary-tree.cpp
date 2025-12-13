
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
            if(root == NULL) return 0;
        queue<TreeNode *> q;
        q.push(root);
        vector<long long> result;
        while( !q.empty()){
            int len = q.size();
            long long sum = 0;
            for(int i = 0; i < len; i++){
                TreeNode  * node = q.front();
                q.pop(); //ths func doesnt return front of q   ueue
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
           result.push_back(sum);
        }
        sort(result.begin(), result.end());
        if(k > result.size()) return -1;
        return result[ result.size()-k];
    }
};