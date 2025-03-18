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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(head == NULL || k==0 || head -> next == NULL){
            return head;
        }
        int len = 1;
        while(temp -> next != NULL){
            temp = temp -> next;
            len++;
        }
        temp -> next = head;
        k = k % len;
        int end = len - k;

        while(end != 0){
            temp = temp -> next;
            end--;
        }
        head = temp -> next;
        temp -> next = NULL;

        return head;
    }
};