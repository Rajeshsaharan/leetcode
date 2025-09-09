int rangeBitwiseAnd(int left, int right) {
    unsigned result = 0;
    int i = 31;
    while(i >= 0){
        int left_masked = left & 1u << i;
        int  right_masked = right & 1u << i;
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