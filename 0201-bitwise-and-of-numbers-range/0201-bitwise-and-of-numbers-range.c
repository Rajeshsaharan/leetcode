int rangeBitwiseAnd(int left, int right) {
    unsigned result = 0;
    int i = 31;
    while(i >= 0){
        unsigned mask = 1u << i;
        int left_masked = left & mask;
        int  right_masked = right & mask;
        if(left_masked == right_masked){
            if(left_masked == 0){
                result |= 0u <<i;
            }else{
                result |= 1u << i;
            }
            
        }else{
            break;
        }
        i--;
    }
    return result;
}