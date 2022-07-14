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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int rootNode = 0;
      return builder(preorder,inorder,rootNode,0,inorder.size()-1);    
}
    TreeNode* builder(vector<int>& preorder, vector<int>& inorder,int& rootNode,int left,int right){
        if(left > right) return NULL;
        int pivot = left;
        while(inorder[pivot] != preorder[rootNode]) pivot++;
        
        rootNode++;
        TreeNode* node = new TreeNode(inorder[pivot]);
        node->left = builder(preorder,inorder,rootNode,left,pivot-1);
        node->right = builder(preorder,inorder,rootNode,pivot+1,right);
        
        return node;
    }
};