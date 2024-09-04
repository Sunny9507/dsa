class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        int count = 0;

        // Count the frequency of each element
        for (int num : nums) {
            frequency[num]++;
        }

        // Iterate over the frequencies
        for (auto& entry : frequency) {
            int num = entry.first;
            int freq = entry.second;

            // Check if the complement exists
            int complement = num + k;
            if (frequency.count(complement) > 0) {
                // If k is 0, ensure we don't count the same pair twice
                if (k == 0 && freq > 1) {
                    count++;
                } else if (k != 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
