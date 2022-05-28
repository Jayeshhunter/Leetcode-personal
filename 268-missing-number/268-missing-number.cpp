class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> arr;
          int i;

      for(i=0;i<nums.size();i++){
if(arr[nums[i]] == 0){
  arr[nums[i]] = 1;
}else{
        arr[nums[i]]++;
}      
}
      for(i=0;i<=nums.size();i++){
        if(arr[i] == 0){
          return i;
        }
      }
      return -1;
    }
};