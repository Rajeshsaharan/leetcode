void print(char * array, int count){
    int i = 0;
    while(i < count){
        printf("%c", array[i]);
        i++;
    }
    printf("\n");
}


bool isPalindrome(char* s) {
    int count =0, i =0, j= 0;
    while(s[i] != '\0'){
        if(s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 || s[i] >= 48 && s[i]<= 57 )count++;
        i++;
    }
    if( count == 0 ) return 1;
    char result[count];
    i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 65 && s[i] <=90) result[j++] = s[i] +32;
        if(s[i] >=97 && s[i] <=122 || s[i] >= 48 && s[i] <= 57 ) result[j++] =s[i];
        i++;
    }
    print(result,  count);
    i = count-1; j = 0;
    while(i != j && i > -1){
        if(result[i] != result[j]) return 0;
        i--;
        j++;
    }
    return 1;

}