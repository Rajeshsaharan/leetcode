int maxDistinct(char* s) {
    int i = 0;
    int arr[26] = {0};
    int count = 0;
    while(s[i] != '\0'){
        if(arr[s[i]-97] == 0) count++;
        arr[s[i]-97]++;
        i++;
    }
    return count;
}