class Solution {
public:
  vector<vector<string>>result;
  bool is_able(vector<string>& grid,int row,int col){
    int i,j;
    for(i=row;i>=0;--i){
      if(grid[i][col] == 'Q') return false; 
    }
    for(i=row,j=col;i>=0 && j>=0;--i,--j){
      if(grid[i][j] == 'Q') return false;
    }
    for(i=row,j=col;i>=0 && j<grid.size();--i,++j){
      if(grid[i][j] == 'Q') return false;
    }
    return true;
  }
  void dfs(vector<string>& grid,int row){
    if(row == grid.size()){
      result.push_back(grid);
      return;
    }
    for(int i=0;i<grid.size();i++){
      if(is_able(grid,row,i)){
        grid[row][i] = 'Q';
        dfs(grid,row+1);
        grid[row][i] = '.';
      }
    }
  }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>ans(n,string(n,'.'));
        dfs(ans,0);
      return result;
    }
};