class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int left = 0, right = 0, maxBeauty = 1;
        
        while (right < n) {
            while (right < n && nums[right] - nums[left] <= 2 * k) {
                maxBeauty = max(maxBeauty, right - left + 1);
                right++;
            }
            left++;
        }
        
        return maxBeauty;
    }
};
