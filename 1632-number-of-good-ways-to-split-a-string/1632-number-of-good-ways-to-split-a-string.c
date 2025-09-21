int numSplits(char* s) {
    int size = strlen(s);
    int freq1[26] = {0};
    int freq2[26] = {0};
    int i = 0;
    int count = 0;
    while (s[i] != '\0') {
        if(freq1[s[i]- 97] > 0) count++;
        freq1[s[i] - 'a']++;
        freq2[s[i]-'a']++;
        i++;
    }
    
    int dp1[size];
    int dp2[size];
    dp1[0] = count;
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