class Solution {
public:
    int calc(vector<int>& nums, int goal) {
        int i=0,j=0,tmp=0,sm=goal;
      if(goal < 0) return 0;
      for(j=0;j<nums.size();j++){
        sm -= nums[j];
        while(sm < 0){
         sm += nums[i++];
        }
        tmp += j-i+1;
      }
      return tmp;
    }
  int numSubarraysWithSum(vector<int>& nums,int goal){
    return calc(nums,goal)-calc(nums,goal-1);
  }
};