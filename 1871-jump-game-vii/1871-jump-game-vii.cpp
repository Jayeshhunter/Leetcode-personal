class Solution {
public:
//  int dp[100001];
//   bool traverse(string &s,int i,int minJump,int maxJump){
//     if(i >= s.size()){
//       return false;
//     }
//     if(i!=0 && s[i] != '0') return false;
//     if(i == s.size()-1){
//       return true;
//     }
    
//     int f1=i+maxJump,f2=s.size()-1;
//     int lim = min(f1,f2);
//     for(int j=i+minJump;j<=lim;j++){
//       if(dp[j] != -1) break;
//       dp[j] = traverse(s,j,minJump,maxJump) == true ? 1 : 0;
//       if(dp[j]){
//         return true;
//       }
//     }
//     return dp[i] = false;
//   }
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.size()-1;
    if(s[n] != '0') return false;
    queue<int> q;
    q.push(0);
    int i=0;
    int curr=0;
    while(!q.empty()){
      i = q.front();
      q.pop();
      if(i == s.size()-1) return true;
      int f1=i+maxJump,f2=s.size()-1,f3 = i+minJump;
      for(int j=max(f3,curr);j<=min(f1,f2);j++){
        if(s[j] == '0') q.push(j);
      }
      curr = min(f1+1,f2+1);
    }
      return false;
  }
};