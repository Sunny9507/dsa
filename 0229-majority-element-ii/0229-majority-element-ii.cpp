class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int mini = nums.size() / 3 + 1;
        vector<int> v;
        
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            if(m[nums[i]] == mini) {
                v.push_back(nums[i]);
            }
            if(v.size() == 2) break;
        }
        
        return v;
    }
};
