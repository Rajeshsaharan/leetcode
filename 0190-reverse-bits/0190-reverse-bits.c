int reverseBits(int n) {
    int count = 31, result =0, i =0;
    while(count >= 0){
        unsigned mask = 1u << i++;
        if(n & mask) result |= 1 << count;
        count--;
    }
    return result;
}