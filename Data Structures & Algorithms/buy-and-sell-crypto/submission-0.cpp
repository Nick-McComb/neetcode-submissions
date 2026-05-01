class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int l = 0;
        int r = 1;
        while(r < prices.size()){
            if(prices[r] - prices[l] < 0){
                l = r;
                r = r + 1;
                continue;
            }
            max_profit = max(max_profit, prices[r] - prices[l]);
            r++;
        }
        return max_profit;
        
    }
};
