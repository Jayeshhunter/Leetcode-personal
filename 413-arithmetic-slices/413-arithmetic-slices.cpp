class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int start=0,end=0,count=0,n=nums.size(),cnt=1,diff=INT_MAX;
      while(end<n){
        if(end-start == 0) end++;
        else if(diff == INT_MAX){
          diff = nums[end]-nums[end-1];
        }else if(nums[end]-nums[end-1] == diff){
          if(++end-start > 2 ) count+= cnt++;
        }else{
          start = --end;
          diff = INT_MAX;
          cnt=1;
        }
      }
      return count;
    }
};