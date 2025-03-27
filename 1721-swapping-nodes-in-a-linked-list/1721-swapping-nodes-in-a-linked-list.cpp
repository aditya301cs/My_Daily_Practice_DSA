
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        if (head == NULL || head->next == NULL) {
            return head;
        }
        // Step 1: Convert linked list to an array
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        // Step 2: Swap k-th element from start and end
        int n = arr.size();
        swap(arr[k - 1], arr[n - k]);

        // Step 3: Reconstruct the linked list with modified values
        if (arr.empty())
            return NULL;

        temp = head;
        for (int i = 0; i < n; i++) {
            temp->val = arr[i];
            temp = temp->next;
        }
        return head;
    }
};