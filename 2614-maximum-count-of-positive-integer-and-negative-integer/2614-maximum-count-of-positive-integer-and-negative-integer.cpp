class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int maxi = INT_MIN;
        int cntP = 0, cntN = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                cntN++;
            }
            else if(nums[i] > 0){
                cntP++;
            }
        }
        maxi = max(maxi, max(cntN, cntP));

        return maxi;
    }
};