class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int balance = 0;
        int deficit = 0;
        int idx = 0;
        for(int i = 0; i < n; i++){
            balance = balance+ gas[i] - cost[i];
            if(balance < 0){
                deficit += abs(balance);
                idx = i + 1;
                balance = 0;
            }
        }
        if(balance - deficit >= 0){
            return idx;
        }

        return -1;

    }
};