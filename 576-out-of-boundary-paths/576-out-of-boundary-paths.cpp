class Solution {
public:
    int DIR[5] = {0,1,0,-1,0};
    int memo[50][50][51];
    int r,c;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        r = m;
        c = n;
        memset(memo,-1,sizeof(memo));
        return checkPath(startRow,startColumn,maxMove);
    }
    int checkPath(int m,int n,int maxMove){
        if(m < 0 || m == r || n <0 || n == c) return 1;
        if(maxMove == 0) return 0;
        if(memo[m][n][maxMove] != -1) return memo[m][n][maxMove];
        int ans=0;
        for(int i=0;i<4;i++){
            ans = (ans + checkPath(m+DIR[i],n+DIR[i+1],maxMove-1))%1000000007;
        }
        return memo[m][n][maxMove] = ans;
    }
};