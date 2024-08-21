class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int operations = 0;

        for(int i=1; i<n; i++) {
            if(s[i] == s[i-1]) {
                operations++;
                s[i] = (s[i-1] == '0') ? '1' : '0';
            }
        }
        return min(operations, n-operations);
    }
};