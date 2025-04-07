class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        queue<string> q;
        q.push("0");
        q.push("1");

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (curr.length() == n) {
                ans.push_back(curr);
                continue;
            }

            // You can always add "1"
            q.push(curr + "1");

            // You can only add "0" if last character is not "0"
            if (curr.back() != '0') {
                q.push(curr + "0");
            }
        }

        return ans;
    }
};