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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
      return currSum(root,0,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum); 
    }
  int currSum(TreeNode* root,int prev,int ts){
    if(root == NULL) return 0;
    int curr = root->val+prev;
    return (curr == ts) + currSum(root->left,curr,ts) + currSum(root->right,curr,ts);
  }
};