// Function to calculate factorial
int fact(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Global variable to track the current permutation index
int per_count = 0;

// Function to store a single permutation in the result array
void store_permutation(int* nums, int** result, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        result[per_count][i] = nums[i];
    }
    per_count++;
}

// Recursive helper function to generate permutations
void helper(int** result, int* nums, int numsSize, int start, int end) {
    if (start == end) {
        store_permutation(nums, result, numsSize);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&nums[start], &nums[i]);           // Swap current element
        helper(result, nums, numsSize, start + 1, end); // Recurse
        swap(&nums[start], &nums[i]);           // Backtrack
    }
}

// Main function to generate permutations
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalPermutations = fact(numsSize);

    // Allocate memory for the result array
    int** result = (int**)malloc(totalPermutations * sizeof(int*));
    for (int i = 0; i < totalPermutations; i++) {
        result[i] = (int*)malloc(numsSize * sizeof(int));
    }

    // Allocate memory for returnColumnSizes
    *returnColumnSizes = (int*)malloc(totalPermutations * sizeof(int));
    for (int i = 0; i < totalPermutations; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    *returnSize = totalPermutations; // Set the return size

    // Initialize the global counter
    per_count = 0;

    // Call the helper function to generate permutations
    helper(result, nums, numsSize, 0, numsSize - 1);

    return result;
}
