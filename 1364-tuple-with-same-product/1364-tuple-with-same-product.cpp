class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int tuples = 0;
        unordered_map<int, int>m;

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int p = nums[i]*nums[j];
                m[p]++;
            }
        }
        for(auto &it : m){
            int prod = it.first;
            int freq = it.second;

            tuples += (freq * (freq-1))/2;

        }
        return tuples * 8;
    }
};