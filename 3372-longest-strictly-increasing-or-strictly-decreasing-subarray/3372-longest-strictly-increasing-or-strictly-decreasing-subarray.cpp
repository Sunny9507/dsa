class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int cnt = 1, cnt1 = 1, maxi = INT_MIN;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                cnt++;
                cnt1 = 1;
            }else if(nums[i] > nums[i+1]){
                cnt1++;
                cnt = 1;
            }
            else {
                cnt = 1;
                cnt1 = 1;
            }
            maxi = max(maxi, max(cnt, cnt1));
        }
        return maxi;
    }
};