class Solution {
public:
    bool isValid(vector<int>& nums, int k, int maxAllow){
        int first = 1, spplit = 0;

        for(int i=0; i<nums.size(); i++){
           
            if(spplit + nums[i] <= maxAllow){
                spplit += nums[i];
            }
            else{
                first++;
                spplit  = nums[i];
            }
        }
        return first <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()),
            h = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;
        while(l <= h){
            int mid = (l + h)/2;
             
            if(isValid(nums, k, mid)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};



