class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0];
        int max_profit = 0;
        
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] > buy_price){
                max_profit = max(max_profit, prices[i] - buy_price);
            }
            else buy_price = prices[i];
        }
        
        return max_profit;
    }
};