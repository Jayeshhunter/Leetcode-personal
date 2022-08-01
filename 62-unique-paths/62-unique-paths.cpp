class Solution {
public:
    int uniquePathscheck(int m,int n,int row,int col,vector<vector<int>>&ans){
        
        if(row == m-1 && col == n-1){
            return 1;
        }
        if(row>=m || col>=n){
            return 0;
        }
        if(ans[row][col] != 0){
            return ans[row][col];
        }
        int rowVal = uniquePathscheck(m,n,row+1,col,ans);
        int colVal = uniquePathscheck(m,n,row,col+1,ans);
        ans[row][col] = rowVal + colVal;
        return ans[row][col];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> ord(m+1,vector<int>(n+1,0));
       return uniquePathscheck(m,n,0,0,ord);  
    }
};