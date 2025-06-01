class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return solve(0,1,1,prices);
    }

    int solve(int idx, int canBuy, int transCount, vector<int>& prices){
        if(idx >= prices.size()) return 0;
        if(transCount == 0) return 0;


        if(canBuy == 1){
            int idle = solve(idx + 1, 1, transCount, prices);
            int buy = -prices[idx] + solve(idx + 1, 0, transCount, prices);
            return max(idle, buy);
        }
        else{
            int idle = solve(idx + 1, 0, transCount, prices);
            int sell = prices[idx] + solve(idx + 1, 1, transCount - 1, prices);
            return max(idle, sell);
        }
    }
};