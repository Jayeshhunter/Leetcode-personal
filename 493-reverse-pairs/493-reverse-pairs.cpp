class Solution {
public:
  
  int merge(vector<int>& nums,int start,int mid,int end){
    int j=mid+1,count=0;
    for(int i=start;i<=mid;i++){
      while(j <= end && (long)nums[i] > (long)2*nums[j] ) {
        j++;
      }
      count += (j-(mid+1));
    }
    vector<int> res;
    int left = start,right=mid+1;
    while(left <= mid && right <= end){
      if(nums[left] <= nums[right]){
        res.push_back(nums[left++]);
      }else{
        res.push_back(nums[right++]);
      }
    }
    
    while(left <= mid){
      res.push_back(nums[left++]);
    }
    while(right <= end){
      res.push_back(nums[right++]);
    }
    
    for(int i=start;i<=end;i++){
      nums[i] = res[i-start];
    }
    return count;
  }
  
  int merge_sort(vector<int>& nums,int l,int r){
    if(l >= r) return 0;
    int mid = (l+r)/2;
    int start = merge_sort(nums,l,mid);
    int end = merge_sort(nums,mid+1,r);
    return start+end+merge(nums,l,mid,r);
  }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
}; 