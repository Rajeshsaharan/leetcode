bool isIsomorphic(char* s, char* t) {
  int arr1[128], arr2[128] , i = 0;
    while(s[i] != '\0'){
        if(arr1[s[i]] == 0 && arr2[t[i]] == 0){
            arr1[s[i]] = t[i];
            arr2[t[i]] = s[i];
        }
        if(arr1[s[i]] !=t[i] && arr2[t[i]] != s[i]) return false;
        i++;
    }
    return true;
}