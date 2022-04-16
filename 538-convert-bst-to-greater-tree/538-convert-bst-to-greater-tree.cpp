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
    int totalSum=0;
    void inorderInverse(TreeNode* root){
        if(!root) return;
        if(root->right) inorderInverse(root->right);
        root->val = (totalSum += root->val);
        if(root->left) inorderInverse(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        inorderInverse(root);
        return root;
    }
};