// simple  math inequility concept to avoid integar overflow
// concept 1 ->  if a * b > c so a > c /b
// concept 2 ->  if a + b > c so  a > c -b

int abs(int x) { return (x < 0) ? -x : x;}

int power_int(int base, int power) {
    if (power == 0)
        return 1;
    int i = 0, value = 1;
    while (i < power) {
        // check for overflow using concept 1
        if (base != 0 && value > INT_MAX / base)
            return -1;
        value *= base;
        i++;
    }
    return value;
}

// counting and store single digit to result array
void reverse_helper(int x, int* result, int* count) {
    if (x >= 0 && x < 10 || x < 0 && x > -10) {
        result[*count] = abs(x);
        return;
    }
    int val = x % 10;
    result[*count] = abs(val);
    x = x / 10;
    *count = (*count) + 1;
    reverse_helper(x, result, count);
}

int reverse(int x) {
    int result[10]; // result array size is 10 for int type
    int count = 0;
    reverse_helper(x, result, &count);
    int i = 0, power = count, total = 0;
    while (i <= count) {
        int val = power_int(10, power);
        if (val == -1) return 0;
        // check overflow using concept 1 || check overflow using concept 2
        if (result[i] > INT_MAX / val || total > INT_MAX - result[i] * val) return 0;
        total += result[i++] * val;
        power--;
    }
    return (x < 0) ? -total : total;
}