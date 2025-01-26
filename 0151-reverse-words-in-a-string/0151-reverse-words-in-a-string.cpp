class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (!word.empty()) {
                ans += " " + word;
            }
        }
        return ans.empty() ? ans : ans.substr(1);
    }
};
