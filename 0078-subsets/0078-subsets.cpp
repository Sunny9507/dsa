class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int numSubsets = 1 << n;
        vector<vector<int>> ans(numSubsets);

        for (int i = 0; i < numSubsets; i++) { // Start from index 0 to include the empty subset
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};
