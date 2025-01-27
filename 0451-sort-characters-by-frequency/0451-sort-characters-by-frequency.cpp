class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128, 0);

        for(auto x : s){
            freq[x]++;
        }

        auto cmp = [&](char a, char b){
            if(freq[a] == freq[b]) return a < b;
            return freq[a] > freq[b];
        };

        sort(begin(s), end(s), cmp);

        return s;
    }
};