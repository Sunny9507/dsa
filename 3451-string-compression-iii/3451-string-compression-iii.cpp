class Solution {
public:
    string compressedString(string word) {
        int n = word.length();

        string cmp = "";
        int i=0;

        while(i < n){
            int cnt = 0;
            char ch = word[i];

            while(i < n && cnt < 9 && word[i] == ch){
                    cnt ++;
                    i++;
            }
            cmp += to_string(cnt) + ch;
        }
        return cmp;
    }
};