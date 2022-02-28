class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        long i=0,j=1;
      if(nums.size() == 0) return {};
      if(nums.size() == 1) return {to_string(nums[0])};
      vector<string> ans;
      
      while(j<nums.size()){
        
        if(nums[j]-1 == nums[j-1]){
          j++;
        }else{
          
          string str="";
          if((j-1)-i == 0){
            str = to_string(nums[i]);
            ans.push_back(str);
            i=j;
            j++;
          }else{
            str = to_string(nums[i]) + "->" + to_string(nums[j-1]);
            ans.push_back(str);
            i=j;
            j++;
          }
        }
        
      }
      if(nums[j-1]-1 == nums[j-2] ){
        string st = to_string(nums[i]) + "->" + to_string(nums[j-1]);
        ans.push_back(st);
      }else{
        string st = to_string(nums[i]);
        ans.push_back(st);
      }
      return ans;
    }
};