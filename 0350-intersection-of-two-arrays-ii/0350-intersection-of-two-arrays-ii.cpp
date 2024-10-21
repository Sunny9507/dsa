class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (int num : nums1) {
            m[num]++;
        }
        
        vector<int> d;
        for (int num : nums2) {
            if (m[num] > 0) {
                d.push_back(num);
                m[num]--;
            }
        }
        
        return d;
    }
};
