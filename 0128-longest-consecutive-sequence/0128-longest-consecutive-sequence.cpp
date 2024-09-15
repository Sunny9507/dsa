#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0; // Check for empty input

        // Sort the numbers
        std::sort(nums.begin(), nums.end());

        int maxi = 1; // Initialize maximum length
        int cnt = 1;  // Initialize current count

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                // Skip duplicates
                continue;
            } else if (nums[i] - nums[i - 1] == 1) {
                // Increment count for consecutive numbers
                cnt++;
            } else {
                // Reset count for non-consecutive numbers
                cnt = 1;
            }
            // Update maximum length
            maxi = std::max(maxi, cnt);
        }

        return maxi; // Return the maximum length found
    }
};