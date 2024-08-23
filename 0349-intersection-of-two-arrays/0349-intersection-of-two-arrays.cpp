#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end()); // Store unique elements of nums1
        unordered_set<int> result; // To store the intersection results

        for (int num : nums2) {
            if (set1.find(num) != set1.end()) { // Check if num is in set1
                result.insert(num); // Add to result if found
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};