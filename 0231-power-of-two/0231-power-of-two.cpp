class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n < 1 ? false : (n & (n - 1)) == 0 ? true : false;
    }
};