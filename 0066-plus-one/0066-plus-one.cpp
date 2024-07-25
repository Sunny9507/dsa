#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit and work backwards
        for (int i = n - 1; i >= 0; i--) {
            // If the current digit is less than 9, just increment it and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // Otherwise, set the current digit to 0 and carry over
            digits[i] = 0;
        }
        
        // If we finish the loop, it means we had a carry out of the most significant digit
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning
        return digits;
    }
};