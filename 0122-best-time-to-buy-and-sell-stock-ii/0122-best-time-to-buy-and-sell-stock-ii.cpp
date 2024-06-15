// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mini= INT_MAX, maxi = 0;
//         int profit1 = 0, profit2 = 0;
//         for(int price : prices){
//             mini = min(mini, price);
//             maxi = max(maxi, price-mini);
//             profit1 = max(profit1, maxi);
//             profit2 = max(profit2, price - profit1)
//         }

//     }



// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int profit = 0;
//         for(int i = 1; i < prices.size(); i++) {
//             if(prices[i] > prices[i-1]) {
//                 profit += prices[i] - prices[i-1];
//             }
//         }
//         return profit;
//     }
// };







class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -INT_MAX, sold = 0;
        for (int price : prices) {
            hold = max(hold, sold - price);
            sold = max(sold, hold + price);
        }
        return max(hold, sold);
    }
};
