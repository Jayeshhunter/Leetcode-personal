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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr = head;
      vector<int> arr;
      
        while(ptr!=NULL){
          arr.push_back(ptr->val); 
          ptr = ptr->next;
        }
      int sz = arr.size();
      swap(arr[k-1] , arr[sz-k]);
      ptr = head;
      int i=0;
      while(ptr!= NULL){
        ptr->val = arr[i++];
        ptr = ptr->next;
      }
      return head;
    }
};