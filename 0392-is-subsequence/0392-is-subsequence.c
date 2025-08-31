bool isSubsequence(char* s, char* t) {
    int size = strlen(s);
    if(size == 0) return 1; //always a subsequence
    int p = 0, arr[size], i =0;
    while(t[i] != '\0'){
        if(s[p] == t[i]) arr[p++] = 1;
        i++;
    }
    i = 0;
    while(i < size){
        if(arr[i] != 1) return 0;
        i++;
    }
    return 1;
    
}