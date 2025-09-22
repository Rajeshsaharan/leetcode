/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* result = calloc((size_t)2, sizeof(int));
    *returnSize = 2;
    int start = 0;
    int end = numbersSize - 1;
    while (start < end) {
        if (numbers[start] + numbers[end] == target) {
            result[0] = start + 1;
            result[1] = end + 1;
            return result;
        }
        if (numbers[start] + numbers[end] > target) end--;
        else start++;
    }
    return result;
}