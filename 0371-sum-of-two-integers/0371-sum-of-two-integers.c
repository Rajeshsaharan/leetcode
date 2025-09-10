int getSum(int a, int b) {
    int i = 0, carry = 0 ,result = 0;
    while(i <32){
        int bit_ai = (a >> i) & 1;
        int bit_bi = (b >> i) & 1;
        int xor_ab = bit_ai ^ bit_bi;
        unsigned int sum = xor_ab ^ carry;
        result |= sum << i;
        carry = (bit_ai & bit_bi ) | carry & xor_ab;
        i++;
    }
    return result;
}