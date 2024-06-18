/*
    story points :
    
    1. i=0, j=0  -> for two ends of our window
    
    2. keep counting vowel if s[j] is 'a' or 'e' or 'i' or 'o' or 'u'
    
    3. when you reach window of size k i.e (j-i+1 == k)
        3.1 update maxV
        3.2 shift window right side (i++) but also adjust vowel count 
            if(s[i] was a vowel)
*/


class Solution {
public:
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int n= s.length();

        int maxV = 0;
        int cnt = 0;
        int i=0, j=0;

        while(j<n){
            if(isVowel(s[j]))
                cnt++;

            if(j-i+1 == k){
                maxV = max(maxV, cnt);
                if(isVowel(s[i]))
                    cnt--;
                i++;
            }
            j++;
        }
        return maxV;
    }
};