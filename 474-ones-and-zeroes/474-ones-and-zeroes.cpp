class Solution {
public:
    int dp[616][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return countVal(strs,m,n,0);
    }
    int countVal(vector<string>& str,int m,int n,int start){
        if(m == 0 && n == 0) return 0;
        if(str.size() <= start || m < 0 || n< 0) return 0;
        if(dp[start][m][n] != -1) return dp[start][m][n];
        
        int sz = str[start].size();
        int zeros = count(str[start].begin(),str[start].end(),'0');
        int ones = sz-zeros;
        
        if(m >= zeros && n >= ones){
         dp[start][m][n] = max(1+countVal(str,m-zeros,n-ones,start+1) , countVal(str,m,n,start+1));
        }else{
            dp[start][m][n] = countVal(str,m,n,start+1);
        }
        return dp[start][m][n];
    }
};