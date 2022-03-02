class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
      int n1=str1.size(),n2=str2.size();  
      vector<vector<int>> tp(n1+1,vector<int>(n2+1,0));
      for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
          if(str1[i-1] == str2[j-1]){
            tp[i][j] = 1+tp[i-1][j-1];
          }else{
            tp[i][j] = max(tp[i-1][j],tp[i][j-1]);
          }
        }
      }
      int i=n1,j=n2;
      string s1="";
      while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
          s1.push_back(str1[i-1]);
          i--;
          j--;
        }else{ 
          if(tp[i-1][j] > tp[i][j-1]){
          s1.push_back(str1[i-1]);
          i--;
        }else{
          s1.push_back(str2[j-1]);
          j--;
        }
             }
      }
      while(i>0){
        s1.push_back(str1[i-1]);
        i--;
      }
      while(j > 0){
        s1.push_back(str2[j-1]);
      j--;
      }
      reverse(s1.begin(),s1.end());
      return s1;
    }
};