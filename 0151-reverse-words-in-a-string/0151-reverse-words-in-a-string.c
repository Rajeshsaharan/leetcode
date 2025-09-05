void reverse_char_array(char * arr, int track, int size){
    int i =track, j = size -1;
    while( i != j && j > i){
        char temp = arr[i];
        arr[i++] = arr[j];
        arr[j--] = temp;
    }
}

char* reverseWords(char* s) {
    int size  = strlen(s);
    char * result = malloc(size +1 * sizeof(char));
    result[0] = '\0';
    int i = size -1,j =0, track =0;
    while(i >= 0){
        if(j > 0 && result[j-1] == s[i] && s[i] == ' '){
            i--;
            continue;
        }
        if(s[i] == ' '){
           reverse_char_array(result, track, j);
           track = j+1;
        }
        result[j++] = s[i--];
    }
    //edge case
    reverse_char_array(result, track,j);
    result[j] = '\0';
    i =0;
    if(result[0] == ' '){
        while(i < j){
            result[i] = result[i+1];
            i++;
        }
        result[i-1] = '\0';
    }
    int len = strlen(result);
    if(result[len -1 ] == ' ') result[len -1] = '\0';
    return result;
}