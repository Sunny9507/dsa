class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int>v;
        
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int sum = 0;
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
            v.push_back(sum);
        }
        int mini = *min_element(v.begin(), v.end());
        return mini;
    }
};