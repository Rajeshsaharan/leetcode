int numSplits(char* s) {
    int size = strlen(s);
    int arr[26] = {0};
    int i = 0;
    while (s[i] != '\0') {
        arr[s[i] - 'a']++;
        i++;
    }

    int count = 0;
    for (int k = 0; k < 26; k++) {
        if (arr[k] > 0)
            count++;
    }
    int dp1[size];
    int dp2[size];
    dp1[0] = count;
    int freq1[26];
    memcpy(freq1, arr, sizeof(arr));

    i = 0;
    int j = 1;
    while (s[i] != '\0' && j < size) {
        freq1[s[i] - 'a']--;
        if (freq1[s[i] - 'a'] == 0) {
            dp1[j] = dp1[j - 1] - 1;
        } else {
            dp1[j] = dp1[j - 1];
        }
        j++;
        i++;
    }
    dp2[size - 1] = count;
    int freq2[26];
    memcpy(freq2, arr, sizeof(arr));

    i = size - 1;
    j = size - 2;
    while (i >= 0 && j >= 0) {
        freq2[s[i] - 'a']--;
        if (freq2[s[i] - 'a'] == 0) {
            dp2[j] = dp2[j + 1] - 1;
        } else {
            dp2[j] = dp2[j + 1];
        }
        j--;
        i--;
    }
    count = 0;
    int z = 1;
    while(z < size){
        if(dp2[z-1] == dp1[z]){
            count++;
        }
        z++;
    }
    return count;
}