class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        int i = 0; //for s
        int j = 0; //for t

        while(i < m && j < n) {
            if(s[i] == t[j]) {
                j++;
            }
            i++;
        }

        return n-j;
    }
};