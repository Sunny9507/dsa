class Solution {
public:
    int minSwaps(std::string s) {
        int close = 0, maxClose = 0;

        for (char c : s) {
            if (c == '[') {
                close--;
            } else {
                close++;
            }
            maxClose = max(close, maxClose);
        }

        return (maxClose + 1) / 2;
    }
};
