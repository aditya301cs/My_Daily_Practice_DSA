class Solution {
public:
    int possibleStringCount(string word) {
        int count =0;
        for(int i=1; i<word.size(); i++){
            if(word[i]!=word[i-1]) continue;
            else count++;
        }
        return count+1;
    }
};