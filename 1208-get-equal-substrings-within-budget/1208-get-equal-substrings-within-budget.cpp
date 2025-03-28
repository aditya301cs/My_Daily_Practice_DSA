class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        
        int maxLen = 0;
        int currCost = 0;
        
        int start = 0, end = 0;

        //How many time is each character is visited
        //Each character in s is visited at most twice
        //i->
        //j->
        //T.C = O(2*n)
        while(end < n) {
            currCost += abs(s[end] - t[end]);
            
            while (currCost > maxCost) {
                currCost -= abs(s[start] - t[start]);
                start++;
            }
            
            maxLen = max(maxLen, end - start + 1);
            end++;
        }
        
        return maxLen;
    }
};