#include <string>

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        string concatenated = s + s;
        
        return concatenated.find(goal) != string::npos;
    }
};