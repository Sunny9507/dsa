class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;
        int start = 0;
        int curr = 0;

        for(int i=0; i<nums.size(); i++){
            curr += nums[i];
            while(curr >= target){
                mini = min(mini, i - start + 1);
                curr -= nums[start++];
            }
        }
        return (mini == INT_MAX) ? 0 : mini;
    }
};