class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for(int i=0; i<s.length(); i++){
            map<char, int>mp;
            for(int j=i; j<s.length(); j++){
                mp[s[j]]++;

                int leastfrequent = INT_MAX;
                int mostfrequent = INT_MIN;

                for(auto it : mp){
                    leastfrequent = min(leastfrequent, it.second);
                    mostfrequent = max(mostfrequent, it.second);
                }
                ans += mostfrequent - leastfrequent;
            }
        }
        return ans;
    }
};