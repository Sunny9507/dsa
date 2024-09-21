class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Sort the input array
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate values of nums[i]
            
            int j = i + 1;  // Pointer j starts just after i
            int k = n - 1;  // Pointer k starts at the end of the array
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0) {
                    j++;  // Increment j to increase the sum
                } else if (sum > 0) {
                    k--;  // Decrement k to decrease the sum
                } else {
                    // Found a triplet with sum equal to zero
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.push_back(temp);
                    
                    j++; k--;  // Move j and k to find the next valid triplet
                    // Skip duplicate values of nums[j] and nums[k]
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return result;
    }
};