int minNumberOperations(int* target, int targetSize) {
    int total_operation = target[0];
    int i = 1;
    while(i < targetSize){
        if(target[i] > target[i-1]){
            total_operation += target[i] - target[i-1];
        }
        i++;
    }
    return total_operation;
}