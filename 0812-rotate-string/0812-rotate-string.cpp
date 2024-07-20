#include <string>

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        // Check if the lengths are different
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenate s with itself
        std::string concatenated = s + s;
        
        // Check if goal is a substring of the concatenated string
        return concatenated.find(goal) != std::string::npos;
    }
};