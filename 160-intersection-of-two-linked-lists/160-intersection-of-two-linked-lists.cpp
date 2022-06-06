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
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        ListNode *a = headA;
        ListNode *b = headB;
        while(a!=b){
            if(a == NULL) a = headB;
            if(b == NULL) b = headA;
            if(a == b){
                break;
            }else{
                a = a->next;
                b = b->next;
            }
        }
        return a;
    }
};