long long minimumSteps(char* s) {
    int count_one = 0;
    int i = 0;
    long long int result = 0;
    while(s[i] != '\0'){
        if(s[i] == '1') count_one++;
        else result += count_one;
        i++;
    }
    return result;
}