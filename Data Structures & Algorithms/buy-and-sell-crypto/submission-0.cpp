class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int profit = 0 ;
        for ( int price : prices){
            int prev_hold = hold;
            int prev_profit = profit;
            hold = max(prev_hold , -price);
            profit = max(prev_profit , hold + price);
        }
        return profit;
    }
};
