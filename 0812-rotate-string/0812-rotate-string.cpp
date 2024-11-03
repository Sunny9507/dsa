class Solution {
public:
    bool rotateString(string s, string goal) {
        string d = s+s;

       if(s.length() != goal.length()){
        return false;
       }

        return d.find(goal) != string::npos;


    }
};