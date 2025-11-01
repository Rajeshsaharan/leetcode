
int is_contains(int* nums, int data, int numsSize) {
    if (numsSize == 0)
        return 0;
    int i = 0;
    while (i < numsSize) {
        if (nums[i] == data)
            return 1;
        i++;
    }
    return 0;
}

int is_contains_binary(int* nums, int data, int numsSize) {
    if(numsSize == 0) return 0;
    int low = 0;
    int high = numsSize - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == data) {
            return 1;
        } else if (nums[mid] < data) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -0;
}

int compare_func(const void * a, const void * b){
    return *(int *)a - *(int *)b;
}


struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    struct ListNode* dummy = malloc(sizeof(*dummy));
    qsort(nums, numsSize, sizeof(*nums), compare_func);
    int i = 0;
    dummy->val = 0;
    dummy->next = head;
    struct ListNode *current = head, *prev = dummy;
    while (current) {
        if (is_contains_binary(nums, current->val, numsSize) == 1) {
            prev->next = current->next;
            current = prev;
        } else {
            prev = current;
        }
        current = current->next;
    }
    return dummy->next;
}