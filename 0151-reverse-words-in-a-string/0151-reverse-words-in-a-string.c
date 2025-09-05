void reverse_char_array(char * arr, int track, int size){
    int i =track;
    int j = size -1;
    while( i != j && j > i){
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}



char* reverseWords(char* s) {
    int size  = strlen(s);
    char * result = malloc(size +1 * sizeof(char));
    result[0] = '\0';
    int i = size -1;
    int j =0; int track =0, not_touch = 1;
    while(i >= 0){
         printf("track i %d & track j %d\n", i, j);
        if(j > 0 && result[j-1] == s[i] && s[i] == ' '){
            i--;
            continue;
        }
        if(s[i] == 32){
           reverse_char_array(result, track, j);
           track = j+1;
        }
        result[j] = s[i];
        i--;
        j++;
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
        result[i] = '\0';
    }
    printf("is is %d\n", result[strlen(result)-1]);
    printf("size of %d", strlen(result));
    if(result[strlen(result) -1 ] == ' ') result[strlen(result)-1] = '\0';
    return result;
}