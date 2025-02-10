class Solution {
public:
    string clearDigits(string s) {
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                j = max(j - 1, 0); //max used to avoid negative
            } else {
                s[j] = s[i];
                j++;
            }
        }

        s.resize(j);
        return s;
    }
};
