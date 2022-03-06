class Solution {
public:
  TreeNode* createTree(int val,unordered_map<int,vector<int>>& pc){
    if(pc.find(val) == pc.end()){
      TreeNode *root = new TreeNode(val);
      
      root->left = NULL;
      root->right = NULL;
      return root;
    }else{
      TreeNode *root = new TreeNode(val);
  
      root->left = pc[val][1]!=-1 ? createTree(pc[val][1],pc) : NULL;
      root->right = pc[val][0]!= -1 ? createTree(pc[val][0],pc) : NULL;
      return root;
    }
  }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int> mp;
      unordered_map<int,vector<int>> pc;
      int parent=0;
        for(auto &it:descriptions){
          mp[it[1]] = it[0];
          if(pc.find(it[0]) == pc.end()){
            pc[it[0]].push_back(-1);
            pc[it[0]].push_back(-1);
            if(it[2] == 1){
              pc[it[0]][1] = it[1];
            }else{
              pc[it[0]][0] = it[1];
            }
        }else{
          if(it[2] == 0){
           pc[it[0]][0] = it[1];
          }else{
          pc[it[0]][1] = it[1];
            }
        }
        }
        for(auto &it:descriptions){
          if(mp.find(it[0]) == mp.end()){
              parent = it[0];
              break;
          }
        }
      
      TreeNode *ans = NULL;
      ans = createTree(parent,pc);
        return ans;
    }
};