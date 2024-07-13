class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x = n / 3;
        
        unordered_map<int, int> freq;
        
        // Count the frequency of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        vector<int> result;
        
        // Find elements with frequency greater than n/3
        for (auto [num, count] : freq) {
            if (count > x) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};