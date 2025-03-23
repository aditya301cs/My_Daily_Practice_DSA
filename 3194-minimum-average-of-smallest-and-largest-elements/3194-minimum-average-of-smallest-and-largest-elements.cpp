class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return 0.0;
        }
        double minValue = numeric_limits<double>::max();
        sort(nums.begin(),nums.end());
        int i = 0, j = n-1;
        while(i<j){
            double res = (nums[i] + nums[j]) / 2.0;
            minValue = min(minValue,res);
            i++;
            j--;
        }
        return minValue;
    }
};