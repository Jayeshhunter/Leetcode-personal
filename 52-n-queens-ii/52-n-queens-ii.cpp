class Solution {
public:
    int ans=0;
    bool is_able(vector<vector<int>>& mat,int row,int col){
        int n = mat[0].size();
        for(int i=0;i<=row;i++){
            if(mat[i][col] == 1) return false;
            if(row - i >= 0 && col - i >= 0 && mat[row - i][col - i]) return false;
		    if(row - i >= 0 && col + i <  n && mat[row - i][col + i]) return false;
        }
        return true;
    }
    
    int dfs(vector<vector<int>>& mat,int row){
        int c = mat[0].size();
        int r = mat.size();
        if(row >= r){
            return 1;
        }
        int ans=0;
        for(int i=0;i<c;i++){
            if(is_able(mat,row,i)){
                mat[row][i] = 1;
                ans += dfs(mat,row+1);
                mat[row][i] = 0;
            }
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        vector<vector<int>> mat(n,vector<int> (n,0));
        return dfs(mat,0);   
    }
};