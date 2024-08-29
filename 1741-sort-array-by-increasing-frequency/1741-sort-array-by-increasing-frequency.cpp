class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>m;
        vector<pair <int, int>>v;
        for(auto x : nums){
            m[x]++;
        }
        
        sort(nums.begin(), nums.end(), [&] (int a, int b){
            return m[a] != m[b] ? m[a] < m[b] : a > b; 
        } );

        return nums;
    }
};