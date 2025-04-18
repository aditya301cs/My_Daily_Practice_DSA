class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>p;

        for(int i = 0; i < gifts.size(); i++){
            p.push(gifts[i]);
        }

        while (k-- && !p.empty()) {
            int pile = p.top();
            p.pop();
            int reducedPile = sqrt(pile);
            p.push(reducedPile);
        }


        long long total = 0;
        while (!p.empty()) {
            total += p.top();
            p.pop();
        }
        return total;
    }
};