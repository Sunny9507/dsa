// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int cnt =  0;
//         for(int i=0; i<nums.size(); i++){
//             for(int j=0; j<nums.size(); j++){
//                 if(nums[j] == nums[i]) cnt++;
//             }
//             if(cnt > nums.size()/2){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };

// Tc: o(n2)
// Sc: O(n)




// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int, int>m;
//         for(int i=0; i<nums.size(); i++){
//             m[nums[i]]++;
//         }

//         for(auto x : m){
//             if(x.second > nums.size()/2){
//                 return x.first;
//             }
//         }
//         return -1;
//     }
// };




class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ele;
        for(int i=0; i<nums.size(); i++){
            if(cnt == 0){ 
                cnt = 1;
                ele = nums[i];
            }else if(nums[i] == ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
       return ele;
    }
};