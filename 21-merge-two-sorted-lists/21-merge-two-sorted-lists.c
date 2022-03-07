/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
  struct ListNode dummy;
  struct ListNode* tail = &dummy;
  while(1){
    if(l1 == NULL){
      tail->next = l2;
      break;
    }else if(l2 == NULL){
      tail->next = l1;
break;
    }
    if(l1->val <= l2->val){
      tail->next = l1;
      l1= l1->next;
    }else{
            tail->next = l2;
     l2 = l2->next;
    }
    tail= tail->next;
  }
  return (dummy.next);
}