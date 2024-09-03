class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result = {-1, -1}; 

        
        if (n == 0) {
            return result;
        }

        
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                result[0] = i; 
                break; 
            }
        }

        if (result[0] == -1) {
            return result;
        }

        
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] == target) {
                result[1] = j; 
                break; 
            }
        }

        return result; 
    }
};