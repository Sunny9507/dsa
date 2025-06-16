class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;

        for (char digit : num) {
            // Remove from stack if current digit is smaller and we can still remove
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);  // Add current digit to stack
        }

        // If we still have digits to remove, remove from the end
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        // Build the final number and remove leading zeros
        string result = "";
        bool leadingZero = true;
        for (char digit : stack) {
            if (leadingZero && digit == '0') continue;
            leadingZero = false;
            result += digit;
        }

        // If result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};
