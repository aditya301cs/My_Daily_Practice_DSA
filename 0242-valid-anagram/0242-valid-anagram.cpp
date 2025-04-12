class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        bool flag = true;

        for(int i=0; i<n; i++){
            if(s[i] != t[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
};