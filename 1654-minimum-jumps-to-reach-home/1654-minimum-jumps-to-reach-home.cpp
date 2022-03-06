class Solution {
public:
  unordered_set<int> st;
  int dp[6005][2];
  int chchaSolve(int pos,int fwd,int bck,int target,int cnt){
    if(st.find(pos)!=st.end() || pos < 0 || pos > 6000)
    {
      return 1e9;
    }
    if(pos == target) return 0;
    if(dp[pos][cnt]!= -1) return dp[pos][cnt];
    dp[pos][cnt] = 1 + chchaSolve(pos+fwd,fwd,bck,target,0);
    dp[pos][cnt] = min(dp[pos][cnt],(cnt) ? 1+chchaSolve(pos+fwd,fwd,bck,target,0) : 1+chchaSolve(pos-bck,fwd,bck,target,1));
    return dp[pos][cnt];
  }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(auto it:forbidden){
          st.insert(it);
        }
      memset(dp,-1,sizeof(dp));
      int ans;
      return (ans = chchaSolve(0,a,b,x,0)) >= 1e9 ? -1 : ans;
    }
};