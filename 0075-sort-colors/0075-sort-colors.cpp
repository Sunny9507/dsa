// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int cnt = 0, cnt1 = 0, cnt2 = 0;
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] == 0) cnt++;
//             else if(nums[i] == 1) cnt1++;
//             else cnt2++;
//         }
//         for(int i =0; i<cnt; i++)
//             nums[i] = 0;    
//         for(int i =cnt; i<cnt+cnt1; i++)
//             nums[i] = 1;
//         for(int i =cnt+cnt1; i<nums.size(); i++)
//             nums[i] = 2;
//     }
// };


// TC: O(2N)
// SC: O(1)



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid  = 0, high = nums.size()-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++; 
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};