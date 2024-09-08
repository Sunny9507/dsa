class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int>m;

        for(int i=0; i<n; i++)
            m[nums[i]]++;

            for(int i=0; i<n; i++){
                    
                if(m.at(nums[i]) == 1)
                    return nums[i];
            }
        return 0;
    }
};