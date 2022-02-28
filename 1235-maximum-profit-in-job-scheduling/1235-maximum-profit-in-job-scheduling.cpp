class Solution {

public:
  int dp[100001];
  int dfs(vector<vector<int>>& ans,int i){
    if(i >= ans.size()) return 0;
    if(dp[i] != -1) return dp[i];
    
    int arq = dfs(ans,i+1);
    
    int left=i,right=ans.size()-1;
    int next_iterator=-1;
    //binary search to find the next non-overlapping interval
    while(left <= right){
      int mid = left + (right-left)/2; 
      if(ans[mid][0] < ans[i][1]){
        left = mid+1;
      }else{
        next_iterator = mid;
        right = mid-1; // to find the closest to the first element we need to move leftwards if any position better than the current mid
      }
    }
    if(next_iterator == -1){
     arq = max(arq,ans[i][2]);
    }else{
      arq = max(arq,ans[i][2] + dfs(ans,next_iterator));
    }
    return dp[i] = arq;
  }
  
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
      vector<vector<int>> ans;
      int n = startTime.size();
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<n;i++){
        ans.push_back({startTime[i],endTime[i],profit[i]});
      }
      sort(ans.begin(),ans.end());
      return dfs(ans,0);
    }
};