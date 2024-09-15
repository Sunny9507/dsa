#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0; 

        std::sort(nums.begin(), nums.end());

        int lastSmaller = INT_MIN;
        int cnt = 1;
        int longest = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] + 1) {
                cnt += 1;
            } else {
                cnt = 1;
            }
            longest = std::max(longest, cnt);
        }

        return longest; 
    }
};
