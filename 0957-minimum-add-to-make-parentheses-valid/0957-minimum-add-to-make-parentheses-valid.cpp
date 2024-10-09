class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0; 
        int closeCount = 0; 
        
        for (char ch : s) {
            if (ch == '(') {
                openCount++; 
            } else if (ch == ')') {
                if (openCount > 0) {
                    openCount--; 
                } else {
                    closeCount++;
                }
            }
        }
        
        return openCount + closeCount;
    }
};