class Solution {
public:
int dp[1001][1001];
  int dfs(vector<vector<int>>& matrix,int val ,int i,int j){
     if(i<0 || j< 0 || i>=matrix.size() || j>=matrix[0].size() || val >= matrix[i][j]){
        return 0;
      }
    if(dp[i][j] != -1) return dp[i][j];
    int l = dfs(matrix,matrix[i][j],i+1,j);
    int r = dfs(matrix,matrix[i][j],i,j+1);
    int u = dfs(matrix,matrix[i][j],i-1,j);
    int d = dfs(matrix,matrix[i][j],i,j-1);
    
    int ans = max({l,r,u,d}) + 1;
    return dp[i][j] = ans;
  }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int ans=INT_MIN;
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
          ans = max(ans,dfs(matrix,-1,i,j));
        }
      }
      return ans;
    }
};