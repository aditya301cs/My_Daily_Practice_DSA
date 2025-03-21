class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHeight = 0;
        int currHeight = 0;

        for(int i=0; i<gain.size(); i++){
            currHeight+=gain[i];

            maxHeight=max(maxHeight,currHeight);
        }
        return maxHeight;
    }
};