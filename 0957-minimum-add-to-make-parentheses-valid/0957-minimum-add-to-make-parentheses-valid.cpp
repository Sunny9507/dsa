class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<char>st;
        for(char c: s){
            if(c == '(') st.push(c);
            else {
                if(st.empty()) cnt++; // koi tha hi nhi 
                else st.pop();
            }
        }
        return cnt + st.size();
    }
};