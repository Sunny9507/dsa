class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
            S.insert(nums[i]);
        
    // check each possible sequence from
    // the start then update optimal length
        for (int i = 0; i < nums.size(); i++) {
        // if current element is the starting
        // element of a sequence
            if (S.find(nums[i] - 1) == S.end()) {
            // Then check for next elements
            // in the sequence
                int j = nums[i];
                while (S.find(j) != S.end())
                    j++;

            // update  optimal length if
            // this length is more
            ans = max(ans, j - nums[i]);
        }
    }
    return ans;
    }
};