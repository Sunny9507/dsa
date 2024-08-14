class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0); // LPS array

        // Construct the LPS array
        int len = 0; // Length of the previous longest prefix
        int i = 1;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // The longest happy prefix is the substring from index 0 to lps[n - 1]
        return s.substr(0, lps[n - 1]);
    }
};
