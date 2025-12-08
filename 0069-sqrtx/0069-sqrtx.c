int mySqrt(int x) {
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