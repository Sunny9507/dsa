class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> left(n),right(n);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],(long long)nums[i]);
            right[n-i-1] = max(right[n-i],(long long)nums[n-i-1]);
        }
        long long maxi = 0;
        for(int i=1;i<n-1;i++){
            maxi = max(maxi,(left[i-1]-nums[i])*right[i+1]);
        }
        return maxi;
    }
};