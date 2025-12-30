int freq[1000001];

int minOperations(int* nums, int numsSize) {
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < numsSize; i++)
        freq[nums[i]]++;

    int rounds = 0;

    for (int i = 0; i < numsSize; i++) {
        int c = freq[nums[i]];
        if (c == 0) continue;

        if (c == 1) return -1;

        rounds += c / 3;
        if (c % 3 != 0) rounds++;

        freq[nums[i]] = 0;
    }

    return rounds;
}
