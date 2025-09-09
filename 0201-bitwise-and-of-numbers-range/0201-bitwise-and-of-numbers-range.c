unsigned int left_shift(unsigned int bin, int pos) {
    unsigned int result;
    __asm__ volatile(
        "mov %1, %0;"  
        "shl %%cl, %0;"
        : "=&r"(result)
        : "r"(bin), "c"(pos) //c for flag cl register
    );
    return result;
}





int rangeBitwiseAnd(int left, int right) {
    unsigned result = 0;
    int i = 31;
    while(i >= 0){
        int left_masked = left & left_shift(1u, i);
        int  right_masked = right & left_shift(1u, i);
        if(left_masked == right_masked){
            if(left_masked == 0){
                result |= left_shift(0u , i);
            }else{
                result |=left_shift(1u, i);
            }
            
        }else{
            break;
        }
        i--;
    }
    return result;
}