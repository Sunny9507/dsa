class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> left; 

        for (int i = 0; i < n; ++i) {
            if (left.empty() || nums[left.back()] > nums[i]) {
                left.push_back(i);
            }
        }

        int maxWidth = 0;

        for (int j = n - 1; j >= 0; --j) {
            while (!left.empty() && nums[left.back()] <= nums[j]) {
                maxWidth = max(maxWidth, j - left.back());
                left.pop_back();
            }
        }

        return maxWidth;
    }
};