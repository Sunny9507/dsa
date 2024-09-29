class Solution {
public:
    char kthCharacter(int k) {
        string a = "a";
        for(int i=0; i<=10; i++){
            int n = a.size();
            for(int j=0; j<n; j++){
                int ind = a[j] - 'a';
                ind++;
                ind %= 26;
                char ch = 'a' + ind;
                a.push_back(ch);
                if(a.size() == k){
                    return ch;
                }
            }
        }
        return 'a';
    }
};