class Solution {
public:
    bool isValid(string s) {
        // Map to store the corresponding values for each type of bracket
        unordered_map<char, int> bracketMap = {
            {'(', -1}, {')', 1},
            {'{', -2}, {'}', 2},
            {'[', -3}, {']', 3}
        };

        stack<char> st; // Stack to keep track of opening brackets

        for (char ch : s) {
            // If it's an opening bracket, push it onto the stack
            if (bracketMap[ch] < 0) {
                st.push(ch);
            }
            // If it's a closing bracket, check if it matches the top of the stack
            else {
                if (!st.empty() && bracketMap[st.top()] + bracketMap[ch] == 0) {
                    st.pop(); // If it matches, remove the top element
                } else {
                    return false; // If it doesn't match, return false
                }
            }
        }

        // If the stack is empty, all brackets are properly closed
        return st.empty();
    }
};