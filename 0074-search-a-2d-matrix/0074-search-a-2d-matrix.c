int binary_search(int ** arr, int i , int n, int target){
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = low + (high - low) / 2; 
        if (arr[i][mid] == target) {
            return 1; 
        }
        if (arr[i][mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return 0; // Target not found
}



bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int i = 0;
    while(i < matrixSize){
        if(binary_search(matrix, i, matrixColSize[i], target)) return true;;
        i++;
    }
    return false;
}