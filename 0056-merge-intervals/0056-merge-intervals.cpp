class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int m = intervals.size();
        vector<vector<int>> ans;

        for(int i = 0; i < m; i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }else{
                vector<int>&v = ans.back();
                int x = v[1];
                //[1,5],[2,4] ---> [1,5]
                if(x >= intervals[i][0]){
                    v[1] = max(intervals[i][1],x);
                }else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};