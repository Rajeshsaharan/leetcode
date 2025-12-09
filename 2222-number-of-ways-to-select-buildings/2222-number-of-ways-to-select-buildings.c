long long numberOfWays(char* s) {
    int freq[2] = {0}; // 0 and 1
    int left_freq[2] = {0};
    int i = 0;

    while (s[i] != '\0') {
        freq[s[i] - '0']++;
        i++;
    }

    i = 0;
    long long count = 0;

    while (s[i] != '\0') {
        freq[s[i] - '0']--;
        left_freq[s[i] - '0']++;

        if (s[i] == '1') {
            if (left_freq[0] != 0 && freq[0] != 0) {
                count += 1LL * left_freq[0] * freq[0];
            }
        } else {
            if (left_freq[1] != 0 && freq[1] != 0) {
                count += 1LL * left_freq[1] * freq[1];
            }
        }
        i++;
    }
    return count;
}
