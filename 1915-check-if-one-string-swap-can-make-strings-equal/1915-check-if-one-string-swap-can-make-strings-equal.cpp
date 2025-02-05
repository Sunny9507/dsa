class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();

        int diff = 0;

        int firstDiff = 0;
        int secDiff = 0;

        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                diff++;
            if(diff > 2){ 
                return false;
            }
            else if(diff == 1){
                firstDiff = i;
            }
            else{
                secDiff = i;
            }
            }
        }
        return (s1[firstDiff] == s2[secDiff] && s1[secDiff] == s2[firstDiff]);
    }
};