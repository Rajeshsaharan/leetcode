

bool checkPerfectNumber(int num) {
    if (num <= 1) return false;
    int total = 1;  //1 and number itself always a divisors
    int i =2;
    while(i * i <= num){
        if(num % i== 0) {
            total += i;
            if(i != num/ i) total += num/i;
        }
        i++;
    }
    return total == num;
}
