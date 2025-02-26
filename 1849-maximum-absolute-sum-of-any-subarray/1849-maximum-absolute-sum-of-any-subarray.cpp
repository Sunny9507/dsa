class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currentSum = nums[0];
        int maxSum = nums[0];

        for(int i=1; i<n; i++){
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        currentSum = nums[0];
        int minSum = nums[0];

        for(int i=1; i<n; i++){
            currentSum = min(nums[i], currentSum + nums[i]);
            minSum = min(minSum, currentSum);
        }

        return max(maxSum, abs(minSum));
    }
};