int compare_func_asc(const void  * a ,const void * b) { return *(int *)a- *(int*)b;}
int compare_func_desc(const void * a, const void * b) { return *(int *)b - *(int *)a; }


int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    int * result;
    result = malloc(sizeof(*result) * spellsSize);
    *returnSize = 0;
    qsort(potions, potionsSize, sizeof(*potions), compare_func_asc);
    int i =0;
    while(i < spellsSize){
        int val = 0;
        int low = 0;
        int high = potionsSize -1;
        while(low <= high){
            int mid = low + (high- low)/2;
            long long one = potions[mid];
            long long two = spells[i];
            long long multi = one * two;
            if(multi < success){
                low = mid+1;
            }else{
                val = potionsSize -  mid;
                high = mid-1;
            }
            
        }
        result[(*returnSize)++] = val;
        i++;
    }
    return result;
}