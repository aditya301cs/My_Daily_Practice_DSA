/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *T1 = headA;
        ListNode *T2 = headB;
        while(T1 != T2){
            if(T1 == NULL){
                T1 = headB;
            }else{
                T1 = T1 -> next;
            }
            if(T2 == NULL){
                T2 = headA;
            }else{
                T2 = T2 -> next;
            }
        }
        return T1;
    }
};