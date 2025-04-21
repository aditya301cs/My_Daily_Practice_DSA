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
    ListNode* reverseList(ListNode* head) {
        // Base case: empty list or last node
        if (head == NULL || head->next == NULL)
            return head;

        // Recursive case
        ListNode* rest = reverseList(head->next);  // reverse rest of list
        head->next->next = head;  // make next node point to current
        head->next = NULL;        // set current node's next to NULL

        return rest;
    }
};
