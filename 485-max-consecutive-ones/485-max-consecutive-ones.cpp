class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start=0,ans=0;
      for(int i=0;i<nums.size();i++){
        if(nums[i] == 0){
          ans = max(ans,start);
          start=0;
        }else{
          start++;
        }
      }

      return max(ans,start);
    }
};