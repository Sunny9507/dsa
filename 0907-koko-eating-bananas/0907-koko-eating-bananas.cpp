class Solution {
public:
    bool canEatAll(vector<int>& piles, int mid, int h){
        int actualHr = 0;

        for(int &x : piles){
            actualHr += x/mid;
            if(x % mid != 0){
                actualHr++;
            }
        }
        return actualHr <= h;
    }
    
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int n =  piles.size();

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int mid = (l + r)/2; // per hour I can eat mid number of bananas

            if(canEatAll(piles, mid, h)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};