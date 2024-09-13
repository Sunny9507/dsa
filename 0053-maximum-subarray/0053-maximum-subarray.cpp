class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
                sum += nums[i];

                if(sum > maxi){
                    maxi = sum;
                }

                if(sum < 0){
                    sum  = 0;
                }
        
        }
    return maxi;
    }
};



// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int max_sum = nums[0];
//         int current_sum = nums[0];
        
//         for (int i = 1; i < n; i++) {
//             current_sum = max(nums[i], current_sum + nums[i]);
//             max_sum = max(max_sum, current_sum);
//         }
        
//         return max_sum;
//     }
// };