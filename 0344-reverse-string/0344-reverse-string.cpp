class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            st.push(s[i]);
        }

        int i = 0;
        while(!st.empty()){
            s[i]=st.top();
            st.pop();
            i++;
        }


        // int start = 0, end = s.size() - 1;
        // while(start<end){
            
            // swap(s[start++],s[end--]);
            //OR
            // int temp = s[start];
            // s[start++] = s[end];
            // s[end--] = temp;

        //}
    }
};