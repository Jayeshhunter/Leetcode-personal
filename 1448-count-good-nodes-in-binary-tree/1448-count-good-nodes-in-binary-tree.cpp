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
class Solution {
public:
  int ans=0;
  void dfs(TreeNode *root, int max){
    if(root == NULL) return;
   if(root->val >= max) {
     ans++;
     max = root->val;
   } 
      dfs(root->left,max);
      dfs(root->right,max);
   
  }
    int goodNodes(TreeNode* root) {
    
    dfs(root,INT_MIN);
      return ans;
    }
};