class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;

        sort(nums.begin(), nums.end());

        int maxi = 0;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                maxi = max(maxi, nums[i+1] - nums[i]);
            }
        }
        return maxi;
    }
};