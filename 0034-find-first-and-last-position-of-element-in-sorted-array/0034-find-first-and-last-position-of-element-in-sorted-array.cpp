class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                ans =  i;
                break;
            }
        }
        int a = -1;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] == target){
                a = i;
                break;
            }
        }
        return {ans, a};
    }
};