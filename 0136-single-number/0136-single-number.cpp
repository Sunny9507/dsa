// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int n = nums.size();

//         for(int i=0; i<n; i++)
//             for(int j=0; j<n; j++){
                    
//                 if(nums[i]) == nums[j])
//                     cnt++;
//             }
//             if(cnt == 1) return nums[i]
//     }
//         return 0;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  
        }
        return result;  
    }
};