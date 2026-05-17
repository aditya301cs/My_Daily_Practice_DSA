class Solution {
public:
    int dp[2001][2001];
    bool solve(string &s, string &p, int n, int m){
        if(n < 0 &&  m < 0){
            return true;
        }

        if(n >= 0 && m < 0){
            return false;
        }

        if(n < 0 && m >= 0){
            for(int k = 0; k <= m; k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[n][m] != -1){
            return dp[n][m];
        }

        // single character match
        if(s[n] == p[m] || p[m] == '?'){
            return dp[n][m] = solve(s, p, n-1, m-1);
        }
        // '*' can:
        // 1. match one character -> (n-1, m)
        // 2. match empty string -> (n, m-1)
        else if(p[m] == '*'){
            return dp[n][m] = solve(s, p, n-1, m) || solve(s, p, n, m-1);
        }
        // mismatch
        else{
            return dp[n][m] = false;
        }
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(s, p , s.length() - 1, p.length()-1);
    }
};