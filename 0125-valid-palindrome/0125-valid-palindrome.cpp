
class Solution {
public:
    bool isPalindrome(std::string s) {
        // Step 1: Filter and normalize the string
        std::string filtered;
        for (char c : s) {
            if (std::isalnum(c)) { // Check if the character is alphanumeric
                filtered += std::tolower(c); // Convert to lowercase and add to filtered string
            }
        }

        // Step 2: Check if the filtered string is a palindrome
        std::string reversed = filtered; // Copy the filtered string
        std::reverse(reversed.begin(), reversed.end()); // Reverse the string

        return filtered == reversed; // Compare filtered string with its reverse
    }
};