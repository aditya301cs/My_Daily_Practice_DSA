class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for (char digit : num){
            while(!st.empty() && st.top() > digit && k != 0){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // Reverse to correct the order
        reverse(ans.begin(), ans.end());

        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;

        ans = ans.substr(i);  // Get the non-zero part
        
        return ans.empty() ? "0" : ans;
    }
};