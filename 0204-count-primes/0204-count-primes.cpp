class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        vector<bool> prime(n + 1, true);
        for (int p = 2; p * p < n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i < n; i += p)
                    prime[i] = false;
            }
        }

        int res = 0;
        for (int p = 2; p < n; p++) {
            if (prime[p]) {
                res++;
            }
        }
        return res;
    }
};