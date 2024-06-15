class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, maxi=0;
        for(int price: prices){
            mini = min(mini, price);
            maxi = max(maxi, price-mini);
        }
        return maxi;
    }
};