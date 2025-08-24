
int countDigits(int num) {
    int count = 0 , digit = num , result = 0;
    while (digit >= 1) {
        digit /= 10;
        count++;
    }
    int divider[count];
    int i = 0;
    digit = num;
    while (digit >= 1) {
        divider[i++] = digit % 10;
        digit /= 10;
    }
    i = 0;
    while (i < count) {
        if (num % divider[i++] == 0) result++;
    }
    return result;
}