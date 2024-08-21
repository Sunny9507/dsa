class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        int startwith_0 = 0;
        int startwith_1 = 0;

        for(int i=0; i<n; i++) {
            if(i % 2 == 0) {
                if(s[i] == '0'){
                    startwith_1++;
                }
                else{
                    startwith_0++;
                }
            }
            else {
                if(s[i] == '1'){
                    startwith_1++;
                }
                else{
                    startwith_0++;
                }
            }
        }
        return min(startwith_0, startwith_1);
    }
};