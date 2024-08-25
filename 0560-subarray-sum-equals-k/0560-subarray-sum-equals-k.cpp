class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> ump;  // To store the cumulative sum frequencies
        int sum = 0, count = 0;
        
        // Initialize with sum 0 occurring once to handle cases where a subarray itself equals k
        ump[0] = 1;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int val = sum - k;
            
            // Check if (sum - k) exists in the map, indicating a valid subarray
            if(ump.find(val) != ump.end()) {
                count += ump[val];
            }
            
            // Add the current cumulative sum to the map
            ump[sum]++;
        }
        
        return count;
    }
};