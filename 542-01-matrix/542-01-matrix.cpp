class Solution {
public:
  vector<pair<int,int>> movement = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int r,int c,int cx,int cy){
      return cx < r && cy<c && cx >= 0 && cy >= 0;
    }
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int,int>> q;
    int c = mat[0].size();
    int r = mat.size();
    vector<vector<int>> visited(r,vector<int>(c,0));
    vector<vector<int>> shortestPath(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        if(mat[i][j] == 0){
          visited[i][j]=1;
          shortestPath[i][j]=0;
          q.push({i,j});
        }
      }
    }
    while(!q.empty()){
      auto it = q.front();
      int rw = it.first;
      int cl = it.second;
      q.pop();
      for(auto nk:movement){
        int nr = rw + nk.first;
        int nc = cl + nk.second;
        if(!isValid(r,c,nr,nc)) continue;
        if(visited[nr][nc]) continue;
        
        visited[nr][nc]=1;
        q.push({nr,nc});
        shortestPath[nr][nc] = shortestPath[rw][cl]+1;
      } 
    }
    return shortestPath;
  }
};