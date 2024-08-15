#include <vector>
#include <string>

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> longestPrefix(n, 0);

        int pre = 0, suf = 1;

        while (suf < n) {
            if (s[pre] == s[suf]) {
                pre++;
                longestPrefix[suf] = pre;
                suf++;
            } else {
                if (pre == 0) {
                    longestPrefix[suf] = 0;
                    suf++;
                } else {
                    pre = longestPrefix[pre - 1];
                }
            }
        }

        // Return the longest prefix which is also a suffix
        return s.substr(0, longestPrefix[n - 1]);
    }
};