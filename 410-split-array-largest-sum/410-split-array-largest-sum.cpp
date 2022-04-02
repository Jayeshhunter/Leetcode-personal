class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
      int l=INT_MIN,r=0;
      for(auto it:nums){
        l = max(l,it);
        r += it;
      }
      int n = nums.size();
      int ans=0;
      while(l <= r){
        int mid = l + (r-l)/2;
        int temp=0,count=0;
        for(int i=0;i<n;i++){
          if(temp+nums[i] <= mid){
            temp += nums[i];
          }else{
            count++;
            temp = nums[i];
          }
        }
        count++;
        if(count <= m) {
          r = mid-1;
          ans = mid;
        }
        else{
         l = mid+1; 
        }
      }
      return ans;
    }
};