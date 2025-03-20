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
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int carry = 0;
        while(temp != NULL) {
            
            int value = (temp->val * 2) + carry;
            temp->val = value % 10;
            carry = value / 10;
            prev = temp;
            temp = temp->next;
        }

        if(carry != 0) {
            prev->next = new ListNode(carry);
        }

        return reverseList(head);
    }
};