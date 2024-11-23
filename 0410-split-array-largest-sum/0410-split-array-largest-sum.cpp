class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
       int low = *max_element(nums.begin(), nums.end());
       int high = accumulate(nums.begin(), nums.end(), 0);

       int ans = low;
       while(low <= high){
        int mid = (low+high)/2;

        int n = no_of_subarrays_with_max_sum_as_mid(nums, mid);
        if(n > k){
            low = mid+1;
        }
        else{
            ans = mid; //minimize ans
            high = mid-1;
        }
       }
       return ans;
    }
    int no_of_subarrays_with_max_sum_as_mid(vector<int>& nums, int mid){
        int sum = 0;
        int cnt = 1;

        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] > mid){
                sum = nums[i];
                cnt++;
            }
            else{
                sum += nums[i];
            }
        }
        return cnt;
    }
};