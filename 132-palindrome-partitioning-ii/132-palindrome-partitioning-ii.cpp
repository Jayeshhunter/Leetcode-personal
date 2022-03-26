class Solution {
public:
 
    int minCut(string s) {
      int n = s.size();
      vector<vector<int>> ans(n+1,vector<int>(n+1,-1));
     
       return solveMCM(s,0,s.size()-1,ans); 
    }
  int solveMCM(string &s,int i,int j,vector<vector<int>> &ans){
    if(i>=j) return 0;
    if(isPallindrome(s,i,j) == 1) return 0;
    if(ans[i][j] != -1) return ans[i][j];
    
    
    int maxi = INT_MAX;
    
    for(int k=i;k<j;k++){
      if(isPallindrome(s,i,k)){
      int temp = 1 + solveMCM(s,k+1,j,ans);
      maxi = min(maxi,temp);
      }
    }
    return ans[i][j] = maxi;
  }
  int isPallindrome(string &s,int i,int j){
    while(i<j){
         if(s[i] != s[j]){
           return 0;
         }
      i++;
      j--;
    }
    return 1;
  }
};