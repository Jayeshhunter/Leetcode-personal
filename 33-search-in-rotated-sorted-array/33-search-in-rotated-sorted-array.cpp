class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i;
      int left,right,mid;
      left = 0;
      right = nums.size()-1;
      while(left<=right){
        mid = left + (right-left)/2;
        if(nums[mid] == target){
          return mid;
        }
        else if(nums[mid] > target){
          if(nums[mid] >= nums[left] && target < nums[left]){
            left = mid + 1;
          }else{
            right = mid-1;
          }
        }
        else{
          if(nums[mid] <= nums[right] && target > nums[right]){
            right = mid-1;
          }else{
            left = mid+1;
          }
        }
      }
      return -1;
    }
};