class Solution {
public:
    int canMakeMBouq(vector<int>& bloomDay, int mid, int k){
        int bouqCnt          = 0;
        int consecutiveCnt = 0;

        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                consecutiveCnt++;
            }else{
                consecutiveCnt = 0;
            }
            if(consecutiveCnt == k){
                bouqCnt++;
                consecutiveCnt = 0;
            }
        }
        return bouqCnt;

    }
    int minDays(vector<int>& bloomDay, int m, int k){
        int l= *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());

        int minDays = -1;
        while(l <= h){
            int mid = (l+h)/2;

            if(canMakeMBouq(bloomDay, mid, k) >= m){
                minDays = mid;
                h = mid-1;
            }else{
                l = mid+1;
            } 
        }
        return minDays;
    }
};