class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Find the first decreasing element from the right
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // If no decreasing element is found, it's the last permutation
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the smallest element greater than nums[i] to the right
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }

        // Swap nums[i] and nums[j]
        swap(nums[i], nums[j]);

        // Reverse the subarray from i + 1 to the end
        reverse(nums.begin() + i + 1, nums.end());
    }
};
