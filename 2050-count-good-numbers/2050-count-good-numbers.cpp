class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long power(long long base, long long exp) {
        long long res = 1;
        while (exp) {
            if (exp % 2) res = res * base % MOD;
            base = base * base % MOD;
            exp /= 2;
        }
        return res;
    }
    
    int countGoodNumbers(long long n) {
        return power(5, (n + 1) / 2) * power(4, n / 2) % MOD;
    }
};
