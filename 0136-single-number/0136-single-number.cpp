class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int>m;

        for(int i=0; i<n; i++)
            m[nums[i]]++;

            for(int i=0; i<n; i++){
                int key = nums[i];
                auto temp = m.find(key);
                if(temp->second == 1)
                    return key;
            }
        return 0;
    }
};