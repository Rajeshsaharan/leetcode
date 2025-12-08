double square_root(int x) {
    long long int low = 0;
    long int high = x;
    long int mid;
    double ans = 0.0;
    while(low <= high){
        mid = (low + high) /2;
        if(mid * mid == x){
            ans = mid;
            break;
        }        
        if(mid * mid < x){
            ans = mid;
            low = mid +1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}

int countTriples(int n) {
    int a  = 1, count = 0;
    while( a< n){
        int b = a+1;
        while(b < n){
            double c = sqrt(a * a + b * b);
            if(c<= n && c ==(int)c) count += 2;
            b++;
        }
        a++;
    }
    return count;
}