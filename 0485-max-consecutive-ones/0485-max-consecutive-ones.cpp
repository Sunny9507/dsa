class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0; // Variable to store the maximum count of consecutive 1's
        int cnt = 0;  // Variable to count the current sequence of 1's
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++; // Increment count if the current element is 1
            } else {
                maxi = max(maxi, cnt); // Update maximum if we hit a 0
                cnt = 0; // Reset count for the next sequence
            }
        }
        
        // Final check to update maxi in case the array ends with 1's
        maxi = max(maxi, cnt);
        
        return maxi; // Return the maximum count of consecutive 1's
    }
};