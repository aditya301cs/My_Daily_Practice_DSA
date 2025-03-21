class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
       int i = 0, j = 0;
       vector<vector<int>> result;

    while (i < firstList.size() && j < secondList.size()) {
        // Find the start and end of the intersection
        int start = max(firstList[i][0], secondList[j][0]);
        int end = min(firstList[i][1], secondList[j][1]);

        // If the start is less than or equal to the end, it means there's an intersection
        if (start <= end) {
            result.push_back({start, end});
        }

        // Move the pointer of the interval with the smaller end
        if (firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }

    return result; 
    }
};