class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
          int n = nums.size(); 
        vector<int> ans(n); 
         
        for (int i = 0; i < n; i++) { 
            int val = nums[i]; 
            int mn = INT_MAX; 
            bool ok = false; 
             
            
            for (int i = 0; i <32; i++) { 
                if ((val >> i) & 1) {  //check set bit
                   
                    int can = val & ~(1 << i); 
                     
                   
                    if (can < 0) continue; 
                     
                    
                    if ((can | (can + 1)) == val) { 
                        if (can < mn) { 
                            mn = can; 
                            ok = true; 
                        } 
                    } 
                } 
            } 
             
            if (ok) { 
                ans[i] = mn; 
            } else { 
                ans[i] = -1; 
            } 
        } 
         
        return ans;
    }
};