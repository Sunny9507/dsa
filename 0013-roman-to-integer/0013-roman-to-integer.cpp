class Solution {
public:
    int num(char c){
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else return 1000;
    }
    int romanToInt(string s) {
        int indx = 0, sum  = 0;

        while(indx < s.size()-1){
            if(num(s[indx]) < num(s[indx+1])){
                sum -= num(s[indx]);
            }
            else {
                sum += num(s[indx]);
            }
            indx++;
        }
        sum += num(s[indx]);
        return sum;
    }
};