class Solution {
public:
    int calPoints(vector<string>& arr) {
        stack<int> st;
        int a, b;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == "+") {
                b = st.top(); st.pop();
                a = st.top();
                st.push(b);
                st.push(a + b);
            } else if (arr[i] == "D") {
                st.push(2 * st.top());
            } else if (arr[i] == "C") {
                st.pop();
            } else {
                st.push(stoi(arr[i]));
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};