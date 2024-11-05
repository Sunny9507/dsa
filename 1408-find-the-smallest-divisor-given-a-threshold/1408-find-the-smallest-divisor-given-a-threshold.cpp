class Solution {
public:
    int sumbyd(vector<int>& nums , int div){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += ceil((double)(nums[i]) / double(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, h = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(l <= h){
            int m = (l+h)/2;

            if(sumbyd(nums , m ) <= threshold){
                ans = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        } 
        return ans;
    }
};