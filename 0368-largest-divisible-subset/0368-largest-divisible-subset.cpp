class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), prevIdx(n, -1);
        int maxLen = 1, idx = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n ; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && lis[i] < lis[j] + 1){
                    lis[i] = 1 + lis[j];
                    prevIdx[i] = j;
                }
                if(lis[i] > maxLen){
                    maxLen = lis[i];
                    idx = i;
                }
            }
        }
        vector<int> res;
        while(idx != -1){
            res.push_back(nums[idx]);
            idx = prevIdx[idx];
        }
        return res;
    }
};