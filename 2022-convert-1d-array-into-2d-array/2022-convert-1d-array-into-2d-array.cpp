//Approach-2 (Using simply math observation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));
        int l = original.size();

        if(m*n != l) {
            return {};
        }

        for(int i = 0; i < l; i++) {
            result[i/n][i%n] = original[i];
        }

        return result;
    }
};