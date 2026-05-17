class Solution {
public:

    int dp[2001][2001];

    bool solve(string &s, string &p, int n, int m){

        // both strings exhausted
        if(n == 0 && m == 0){
            return true;
        }

        // pattern exhausted
        if(m == 0){
            return false;
        }

        // string exhausted
        if(n == 0){

            for(int k = 1; k <= m; k++){
                if(p[k-1] != '*'){
                    return false;
                }
            }

            return true;
        }

        if(dp[n][m] != -1){
            return dp[n][m];
        }

        // character match
        if(s[n-1] == p[m-1] || p[m-1] == '?'){
            return dp[n][m] =
                solve(s, p, n-1, m-1);
        }

        // star case
        else if(p[m-1] == '*'){

            return dp[n][m] =
                solve(s, p, n-1, m) ||   // take character
                solve(s, p, n, m-1);     // take empty
        }

        return dp[n][m] = false;
    }

    bool isMatch(string s, string p) {

        memset(dp, -1, sizeof(dp));

        return solve(s, p, s.length(), p.length());
    }
};