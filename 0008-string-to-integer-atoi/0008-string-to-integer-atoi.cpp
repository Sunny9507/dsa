class Solution {
public:
    int convert(string &s, int index, long num, int sign) {
        // Base case: Stop when non-digit is found or out of bounds
        if (index >= s.length() || !isdigit(s[index])) 
            return sign * num;  

        num = num * 10 + (s[index] - '0');  // Accumulate the number

        // Clamp before further recursion
        if (sign == 1 && num >= INT_MAX) return INT_MAX;
        if (sign == -1 && -num <= INT_MIN) return INT_MIN;

        return convert(s, index + 1, num, sign);  // Recurse to next digit
    }

    int myAtoi(string s) {
        int i = 0, n = s.length(), sign = 1;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        return convert(s, i, 0, sign);
    }
};

