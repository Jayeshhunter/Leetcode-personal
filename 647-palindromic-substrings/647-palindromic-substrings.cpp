class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt=0;
        vector<vector<int>> memo(n,vector<int> (n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                cnt += check(memo,s,i,j);
            }
        }
        return  cnt;
    }
    int check(vector<vector<int>>& memo,string &s,int i,int j){
        if(i >= j) return 1;
        if(memo[i][j] > 0) return memo[i][j];
        return memo[i][j] = (s[i] == s[j]) ? check(memo,s,i+1,j-1) : 0;
    }
};