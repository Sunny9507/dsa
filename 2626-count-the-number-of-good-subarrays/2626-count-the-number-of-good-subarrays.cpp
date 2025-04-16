class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;

        long long result = 0;

        unordered_map<int, int> m;

        long long pairs = 0;

        while(j < n){
            pairs += m[nums[j]];
            m[nums[j]]++;

            while(pairs >= k){
                result += (n - j);
                m[nums[i]]--;
                pairs -= m[nums[i]];
                i++;
            }
            j++;
            }
            return result;
        }
};