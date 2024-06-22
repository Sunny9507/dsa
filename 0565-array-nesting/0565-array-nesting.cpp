class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            int next = i;
            int cnt = 0;
            
            while(nums[next] != -1){
                cnt++;
                int temp = next;
                next = nums[next];
                nums[temp] = -1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};