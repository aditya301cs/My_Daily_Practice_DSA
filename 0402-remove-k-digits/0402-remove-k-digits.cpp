class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        for(char ch : num){
            while(!st.empty() && ch < st.top() && k > 0){
                st.pop();
                k--;  
            }
            if(!st.empty() || ch != '0'){
                st.push(ch);
            }
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string str = "";
        while(!st.empty()){
            char x = st.top();
            str += x;
            st.pop();
        }
        if(str.empty()) return "0";

        reverse(str.begin(), str.end());
        return str;
    }
};