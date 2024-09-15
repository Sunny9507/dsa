class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int indx = -1;

        // Find the first decreasing element from the end
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                indx = i;
                break;
            }
        }

        // If no such element is found, reverse the entire array
        if(indx == -1) {
            reverse(nums.begin(), nums.end());
            return; // Add return here to avoid further processing
        }

        // Find the element just larger than nums[indx] from the end
        for(int i = nums.size() - 1; i > indx; i--) {
            if(nums[i] > nums[indx]) {
                swap(nums[i], nums[indx]);
                break;
            }
        }

        // Reverse the elements after indx
        reverse(nums.begin() + indx + 1, nums.end());
    }
};
