class Solution {
public:
    int maxDepth(string s) {
        int balance = 0;
        int maxi  = 0;

        for(char c : s){
            if(c == '('){
                balance++;
                maxi = max(maxi, balance);
            }
            else if(c == ')'){
                balance--;
            }
        }
        return maxi;
    }
};