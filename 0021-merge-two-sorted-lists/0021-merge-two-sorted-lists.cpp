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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the starting point of the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1; // Link the smaller node to the merged list
                list1 = list1->next; // Move to the next node in list1
            } else {
                tail->next = list2; // Link the smaller node to the merged list
                list2 = list2->next; // Move to the next node in list2
            }
            tail = tail->next; // Move the tail pointer
        }
        
        // Link the remaining nodes from either list1 or list2
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // Return the head of the merged list
        return dummy.next;
    }
};
