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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
      stack<int> s2;
      while(l1){
        s1.push(l1->val);
        l1 = l1->next;
      }
      while(l2){
        s2.push(l2->val);
        l2=l2->next;
      }
      int carry=0;
      ListNode *ans = NULL;
      while(!s1.empty() && !s2.empty()){
        int sum = carry + s1.top() + s2.top();
        s1.pop();
        s2.pop();
        carry = sum/10;
        ans = appFront(sum%10,ans);
      }
      while(!s1.empty()){
        int sum = carry + s1.top();
        s1.pop();
        carry = sum/10;
        ans = appFront(sum%10,ans);
      }
      while(!s2.empty()){
        int sum = carry + s2.top();
        s2.pop();
        carry = sum/10;
        ans = appFront(sum%10,ans);
      }
      if(carry != 0){
        ans = appFront(carry,ans);
      }
      return ans;
    }
    ListNode* appFront(int sum,ListNode* ans){
      ListNode *tmp = new ListNode(sum);
      tmp->next = ans;
      return tmp;
    }
  
};