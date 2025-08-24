void helper(int num, int * result, int digit){
    if(digit < 1) return;
    int divider = digit % 10;
    if(num % divider ==0) (*result)++;
    digit /= 10;
    helper(num, result, digit);
}
int countDigits(int num) {
   int digit = num;
   int result = 0;
   helper(num, &result, digit);
   return result;
}