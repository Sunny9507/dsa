class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if(s.empty()) return "";
        
        sort(s.begin(), s.end());

        string & first = s[0];
        string & second = s[s.size()-1];

        string result;
        for(int i=0; i<first.length(); i++){
            if(first[i] != second[i]){
                break;
            }
            else{
                result += first[i];
            }
        }
        return result;
    }
};