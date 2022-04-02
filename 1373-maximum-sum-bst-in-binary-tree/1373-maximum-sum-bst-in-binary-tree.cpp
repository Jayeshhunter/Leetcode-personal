/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int maxi;
class ini{
  public:
    int ms;
    int mi; //to make the left element of a node if including it is a valid subtree
    int ma; //to make the right element of a  node if including it is a valid bst
    bool bst;
  ini(){
    bst = true;
    ms=0;
    ma=INT_MIN;
    mi=INT_MAX;
  }
};

class Solution {
public:
  
    ini maxSum(TreeNode* root){
      if(root == NULL) return ini();
      ini p; 
      ini pl = maxSum(root->left);
      ini pr = maxSum(root->right);
    
      if(pl.bst == true && pr.bst == true && root->val > pl.ma && root->val < pr.mi){
        p.bst = true;
        p.ms = pl.ms + pr.ms + root->val;
        p.ma = max(root->val,max(pl.ma,pr.ma));
        p.mi = min(root->val,min(pl.mi,pr.mi));
      }else{
        p.bst = false;        
        p.ms = max(pl.ms,pr.ms);
      }
      maxi = max(maxi,p.ms);
      return p;
    }
  
    int maxSumBST(TreeNode* root) {
      maxi = INT_MIN;    
      maxSum(root);
      return maxi > 0 ? maxi : 0;
    }
};