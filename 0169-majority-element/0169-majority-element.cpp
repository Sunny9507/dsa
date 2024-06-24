class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int maj = NULL;

        for(int i=0; i<n; i++){
            if(cnt == 0){
                cnt = 1;
                maj = nums[i];
            }
            else if(nums[i] == maj){
                cnt++;
            }
            else {
                cnt--;
            }
        }
        return maj;
    }
};