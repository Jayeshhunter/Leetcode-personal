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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            sum=0;
            int sz = q.size();
            while(sz--){
                TreeNode *tr = q.front();
                q.pop();
                sum += tr->val;
                if(tr->left) q.push(tr->left);
                if(tr->right) q.push(tr->right);
            }
        }
        return sum;
    }
};