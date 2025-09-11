bool canConstruct(char* ransomNote, char* magazine) {
    char * a = ransomNote , *b = magazine;
    int  arr[26], i =0;
    while(b[i] != '\0'){
        arr[b[i] - 97]++;
        i++;
    }
    i = 0;
    while(a[i] != '\0'){
         if(arr[a[i]-97] < 1) return false;
         arr[a[i]-97]--;
         i++;
    }
    return true;
}