class Solution {
public:
    int solve(int n, int p) {
        if(n == 0) {
            return true;
        }

        if(pow(3, p) > n) {
            return false;
        }

        bool p_ko_lelo = solve(n - pow(3, p), p+1);

        bool p_ko_nahi_lo = solve(n, p+1);

        return p_ko_lelo || p_ko_nahi_lo;
    }

    bool checkPowersOfThree(int n) {
        return solve(n, 0);
    }
};
