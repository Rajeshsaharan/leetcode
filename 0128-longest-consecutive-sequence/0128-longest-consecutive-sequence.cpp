class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        int i =0;
        while(i < nums.size()){
            minHeap.push(nums[i]);
            i++;
        }
        int count = 0;
        int max = INT_MIN;
        int first = minHeap.top();
        minHeap.pop();
        while(!minHeap.empty()){
            int second = minHeap.top();
            if(first == second){
                minHeap.pop();
                continue;
            }else if( first +1 == second){
                count++;
            }else{
                max = fmax(max, count);
                count = 0;
            }
            first = second;
            minHeap.pop();
        }
        max = fmax(max, count);
        return max+1;
    }
};