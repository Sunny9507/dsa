class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rec) {
        int m = rec.size();
        
        map<int,int> mp;
        map<int,int> mp2;
        for(auto r : rec)
        {
            mp[r[0]+1]++;
            mp2[r[1]+1]++;
            mp[r[2]]--;
            mp2[r[3]]--;
        }
        int cnt = 0 , cnt2 = 0;
        int prefixSumX = 0, prefixSumY = 0;
        for(auto [c,val] : mp)
        {
            prefixSumX += val;
            if(prefixSumX ==0) 
            {
                cnt++;
            }
        }
        for(auto [c,val] : mp2)
        {
            prefixSumY += val;
            if( prefixSumY ==0){
                cnt2++;
            }
        }

        if(cnt>2 || cnt2 >2)
        {
            return true;
        }
        return false;
    }
};