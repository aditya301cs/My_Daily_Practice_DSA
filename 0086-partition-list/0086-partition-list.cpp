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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp1 = new ListNode(0);  
        ListNode* temp2 = new ListNode(0);  
        ListNode* t1 = temp1;  
        ListNode* t2 = temp2;  

        while (head) {
            if (head->val < x) {
                t1->next = head;  
                t1 = t1->next;
            } else {
                t2->next = head;  
                t2 = t2->next;
            }
            head = head->next;
        }

        t2->next = nullptr;   
        t1->next = temp2->next;  

        return temp1->next;  
    }
};
