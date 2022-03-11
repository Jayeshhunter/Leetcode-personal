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
        if(!head) return NULL;
        int len=1;
      ListNode *ptr = head;
      while(ptr->next){
        ptr = ptr->next;
        len++;
      }
      ptr->next = head;
      
      if(k %= len){
        for(int i=0;i<len-k;i++) ptr = ptr->next;
      }
      ListNode* ans = ptr->next;
      ptr->next = NULL;
      return ans;
    }
};