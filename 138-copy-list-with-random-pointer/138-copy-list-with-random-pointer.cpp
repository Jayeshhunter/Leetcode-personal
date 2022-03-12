/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
          return head;
        }
        Node* node = new Node(head->val);
        Node* t = head;
      Node* temp = node;
      while(head){
          Node* k = head->next;
        head->next = node;
        node->next = k;
        head = head->next->next;
        if(head){
          node = new Node(head->val);
        }
      }
      head = t;
      while(head){
        if(head->random && head->next){
        head->next->random = head->random->next;  
        }
        head=head->next->next;
      }
      
      head = t;
      Node* res = new Node(0);
      t = res;
      while(head){
        res->next = head->next;
        res = res->next;
        head->next = head->next->next;
        head = head->next;
      }
      return t->next;
    }
};