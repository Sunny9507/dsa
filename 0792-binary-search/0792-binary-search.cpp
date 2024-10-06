class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int h, int target){
        if(l > h) return -1;
        
        
        int m = (l+h)/2;

        if(nums[m] == target) return m;

        else if(nums[m] < target) 
            return binarySearch(nums, m + 1, h, target);

            return binarySearch(nums, l, m-1, target);
            
        
    }


    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};