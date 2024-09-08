class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        int n = nums.size();
        
        // XOR all the numbers in the array
        for (int i = 0; i < n; i++) {
            xor2 ^= nums[i];
            xor1 ^= (i+1);
        }
        
        // XOR all the indices from 0 to n
        // for (int i = 0; i <= n; i++) {
        //     xor1 ^= i;
        // }
        
        // The missing number is the XOR of both results
        return xor1 ^ xor2;
    }
};