class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        if(k == n) {
            int total = 0;
            for(int x : cardPoints)
                total += x;
            return total;
        }

        int leftSum = 0;
        for(int i = 0; i < k; i++)
            leftSum += cardPoints[i];

        int maxSum = leftSum;
        int rightSum = 0;
        int rightIndex = n - 1;

        for(int i = k - 1; i >= 0; i--){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex--];
            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};
