class Solution {
private:
    bool check(string &s, string &st, int k) {
        int idx1 = 0, idx2 = 0;
        int n = s.size(), m = st.size();
        while(idx1 < n) {
            if(idx2 < m && s[idx1] == st[idx2]) {
                idx1++;
                idx2++;
            }
            else {
                if(idx2 == m) {
                    idx2 = 0;
                    k--;
                }
                else idx1++;
            }
        }
        if(idx2 == m) k--;

        return k <= 0;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        q.push(""); string ans = "";

        while(!q.empty()) {
            string temp = q.front();
            q.pop();

            for(char ch = 'a'; ch <= 'z'; ch++) {
                string st = temp + ch;
                if(check(s, st, k)) {
                    if(st.size() > ans.size() || st > ans) {
                        ans = st;
                        q.push(ans);
                    }
                }
            }
        }

        return ans;
    }
};