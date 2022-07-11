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
  void khojo(vector<int> &res,int level,TreeNode* root){
    if(root == NULL) return;
    if(res.size() < level) res.push_back(root->val);
    khojo(res,level+1,root->right);
    khojo(res,level+1,root->left);
  }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        khojo(res,1,root);
    return res;
    }
};