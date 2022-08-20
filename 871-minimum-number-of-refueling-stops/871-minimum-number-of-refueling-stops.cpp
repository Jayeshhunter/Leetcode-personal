class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      int n = stations.size();  
      long dp[501] = {startFuel};
      for(int i=0;i<n;i++){
        for(int t=i;t>=0 && dp[t] >= stations[i][0];t--){
          dp[t+1] = max(dp[t+1],dp[t]+stations[i][1]);
        }
      }
      for(int i=0;i<=n;i++){
        if(dp[i] >= target) return i;
      }
      return -1;
    }
};