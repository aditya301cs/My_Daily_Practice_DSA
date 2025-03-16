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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases such as removing the first node
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        
        // Move the first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move both pointers until the first pointer reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Remove the nth node from the end
        second->next = second->next->next;
        
        // Return the head of the modified list
        return dummy.next;
    }
};
