class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        long long n = nums.size();
        long long total = (n*(n+1))/2;
        return total - sum;
    }
};