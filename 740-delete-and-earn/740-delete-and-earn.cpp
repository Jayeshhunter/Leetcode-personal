class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> a1(10002);
      for(int i=0;i<nums.size();i++){
        a1[nums[i]]+= nums[i];
      }
      vector<int>dp(10002);
      dp[1]=a1[1];
      dp[2]=max(a1[1],a1[2]);
      for(int i=3;i<dp.size();i++){
        dp[i] = max(dp[i-1],dp[i-2]+a1[i]);
      }
      return max(dp[10000],dp[9999]);
    }
};