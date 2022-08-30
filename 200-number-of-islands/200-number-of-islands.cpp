class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i,j,r,c,count=0;
      r = grid.size();
      c = grid[0].size();
      for(i=0;i<r;i++){
        for(j=0;j<c;j++){
          if(grid[i][j] == '1'){
            count++;
            hilter(grid,i,j);
          }
        }
      }
      return count;
    }
  void hilter(vector<vector<char>>& grid,int row,int col){
    if(row<0 || col<0 || row >= grid.size()|| col >= grid[0].size() || grid[row][col] != '1'){
      return;
    }
    grid[row][col] = '0';
    hilter(grid,row+1,col);
    hilter(grid,row-1,col);
    hilter(grid,row,col+1);
    hilter(grid,row,col-1);
  }
};