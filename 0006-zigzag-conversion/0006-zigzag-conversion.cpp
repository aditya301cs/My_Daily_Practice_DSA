class Solution {
public:
    string convert(string s, int numRows) {

        if (s.length() == 1 || numRows == 1) {
            return s;
        }

        vector<string> rowStrings(numRows);

        int index = 0;
        int i = 0;   // row index

        while (index < s.length()) {

            // Downward motion
            while (index < s.length() && i < numRows) {
                rowStrings[i].push_back(s[index++]);
                i++;
            }

            // Move upward diagonally
            i -= 2;

            while (index < s.length() && i > 0) {
                rowStrings[i].push_back(s[index++]);
                i--;
            }
        }

        // Build final result AFTER the loop
        string result = "";
        for (int r = 0; r < numRows; r++) {
            result.append(rowStrings[r]);
        }

        return result;
    }
};
