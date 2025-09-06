int reverseBits(int n) {
    int count = 31, result =0;
    int i =0;
    while(count >= 0){
        unsigned mask = 1u << i;
        if(n & mask){
            printf(" count -> %d and %d\n", count, 1);
            result |= 1 << count;
        }else{
            printf("count -> %d and %d\n", count, 0);
            result |= 0 << count;
        }
        count--;
        i++;
    }
    return result;
}