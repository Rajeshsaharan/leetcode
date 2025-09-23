class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int size = people.size();
        int i = 0;
        int j = size-1;
        int count = 0;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            }else j--;
            count++;
            
        }
        return count;
    }
};