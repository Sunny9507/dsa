class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string str = to_string(x);
        string reversed = str;
        reverse(reversed.begin(), reversed.end());
        return str == reversed;
    }
};