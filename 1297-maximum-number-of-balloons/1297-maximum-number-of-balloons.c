int check_ballon(int * arr, int * index){
    int i = 0;
    int a_value = arr[index[i]];
    int b_value = arr[index[i+1]];
    int l_value = arr[index[i+2]];
    int n_value = arr[index[i+3]];
    int o_value = arr[index[i+4]];
    i =0;
    if(a_value >=1 && b_value >=1 && l_value >=2 && n_value >=1 && o_value >=2){
        arr[index[i]]-- ,arr[index[i+1]]-- , arr[index[i+2]] = l_value -2, arr[index[i+3]]--;
        arr[index[i+4]] = o_value -2 ;
        return 1;
    }
    return 0;
}


int maxNumberOfBalloons(char* text) {
    int arr[26];
    int index[] ={0,1, 11, 13, 14}; //a b l n o
    int i = 0;
    while(text[i] != '\0') arr[text[i++] - 97]++;
    int count = 0, terminate = 1;
    while(terminate != 0){
        int result = check_ballon(arr, index);
        if(result == 0) terminate = 0;
        else count++;
    }
    return count;
}