int smallestNumber(int n) {
    int i = 0, value;
    while(i < 32) if(pow(2,i++) > n) break;
    return pow(2, i-1)-1; 
}