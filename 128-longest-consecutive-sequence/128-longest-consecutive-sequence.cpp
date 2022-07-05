class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dp(nums.begin(),nums.end());
        int res=1;
      if(nums.size() == 0) return 0;
      for(int n:nums){
        if(dp.find(n) == dp.end()) continue;
        dp.erase(n);
        int prev = n-1,next=n+1;
        while(dp.find(prev)!=dp.end()) dp.erase(prev--);
        while(dp.find(next)!=dp.end()) dp.erase(next++);
        res=max(res,next-prev-1);
      }
      return res;
    }
};