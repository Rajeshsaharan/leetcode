int rangeBitwiseAnd(int left, int right) {
    unsigned result = 0;
    int i = 31;
    while(i >= 0){
        unsigned mask = 1u << i;
        int left_masked = left & mask;
        int  right_masked = right & mask;
          printf("i -> %d and for mask1 %d and mask2 %d\n", i, left & mask, right & mask);
        if(left_masked == right_masked){
            if(left_masked == 0){
                printf("%d, 0\n", i);
                result |= 0u <<i;
            }else{
                printf("%d, 1\n", i);
                result |= 1u << i;
            }
            
        }else{
            break;
        }
        i--;
    }
    return result;
}