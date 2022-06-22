class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0,right=nums.size()-1,kth;
      while(true){
        int idx = partition(nums,left,right);
        if(idx == k-1){
          kth = nums[idx];
          break;
        }
        if(k-1 > idx){
          left = idx+1;
        }else{
          right = idx-1;
        }
      }
      return kth;
    }
  int partition(vector<int>& nums,int left,int right){
    int l=left+1,r=right,pivot=nums[left];
    while(l<=r){
      if(nums[l] <pivot && nums[r] > pivot){
        swap(nums[l++],nums[r--]);
      }
      if(nums[l] >= pivot){
        l++;
      }
      if(nums[r] <= pivot){
        r--;
      }
    }
swap(nums[left],nums[r]);
    return r;
  }
};