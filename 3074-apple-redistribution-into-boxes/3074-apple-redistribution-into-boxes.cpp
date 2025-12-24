class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int count = 1;
        int requiredSum = 0;
        int totalSum = 0;
        int n = capacity.size();
        sort(capacity.begin(), capacity.end());
        for(int i = 0; i < apple.size(); i++){
            totalSum += apple[i];
        }
        for(int i = n - 1; i >= 0; i--){
            requiredSum += capacity[i];
            if(requiredSum < totalSum){
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};