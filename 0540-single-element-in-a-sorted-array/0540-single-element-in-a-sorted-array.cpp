class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int result = 0;
        for (int num : arr) {
            result ^= num; 
        }
        return result; 
    }
};