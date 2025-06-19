class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int cnt = 1;

        int minVal = nums[0];

        for(int i=0; i<nums.size(); i++){
            if(nums[i] - minVal > k){
                cnt++;
                minVal = nums[i];
            }
        }
        return cnt;
    }
};