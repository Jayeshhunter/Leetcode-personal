class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int maxVal = 0;  
      for(int i=0;i<grid.size();i++){
          for(int j=0;j<grid[0].size();j++){
            if(grid[i][j] == 1){
            maxVal = max(maxVal,maxArea(grid,i,j));
            }
            }
        }
      return maxVal;
    }
  int maxArea(vector<vector<int>>& grid,int i,int j){
    if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j] == 1){
      grid[i][j]=0;
      return 1+maxArea(grid,i-1,j)+maxArea(grid,i+1,j)+maxArea(grid,i,j+1)+maxArea(grid,i,j-1);
    }
    return 0;
  }
};