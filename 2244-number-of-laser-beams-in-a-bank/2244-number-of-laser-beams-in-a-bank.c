int numberOfBeams(char** bank, int bankSize) {
   int i = 0;
   int p_r_ones =0, total = 0;
   while(i < bankSize){
    int j = 0;
    int this_r_ones = 0;
    while(bank[i][j] != '\0'){
        if(bank[i][j] == '1') this_r_ones++;
        j++;
    }
    if(p_r_ones != 0 && this_r_ones != 0){
        total += this_r_ones * p_r_ones;
    }
    if(this_r_ones != 0) p_r_ones = this_r_ones;
    i++;
   }
   return total;
}