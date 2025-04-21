#include <stack>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        // Step 1: Push all values to stack
        while (temp) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Step 2: Compare while popping
        temp = head;
        while (temp) {
            int top = st.top();
            st.pop();
            if (top != temp->val) return false;
            temp = temp->next;
        }

        return true;
    }
};
