class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0, sell = 0;
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] >= prices[i - 1]) {
                sell = i ;
            } else
               { profit += prices[sell] - prices[buy];
            sell = buy = i;
               }
        }
        profit += prices[sell] - prices[buy];
        return profit;
    }
};