class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        
        if (n > m) return false;

        vector<int> s1Freq(26, 0), windowFreq(26, 0);

        
        for (int i = 0; i < n; ++i) {
            s1Freq[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }

        
        for (int i = n; i < m; ++i) {
            if (s1Freq == windowFreq) {
                return true;  
            }

            windowFreq[s2[i - n] - 'a']--;  
            windowFreq[s2[i] - 'a']++;   
        }

        return s1Freq == windowFreq;
    }
};
