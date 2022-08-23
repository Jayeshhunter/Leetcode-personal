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
    bool isPalindrome(ListNode* head) {
  ListNode *ptr=head;
      stack<int> st;
      int flag = 1;
      while(ptr!=NULL){
        st.push(ptr->val);
        ptr=ptr->next;
      }
      ptr = head;
      int valu;
      while(ptr!=NULL){
        valu = st.top();
        if(valu != ptr->val){
          flag = 0;
          break;
        }
        st.pop();
        ptr = ptr->next;
      }
      if(flag == 1){
        return true;
      }else{
        return false;
      }
      
    }
};