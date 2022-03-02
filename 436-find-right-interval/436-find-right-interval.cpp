class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
      vector<vector<int>> arr;
      for(int i=0;i<intervals.size();i++){
        arr.push_back({intervals[i][0],i});
      }
      sort(arr.begin(),arr.end());
      vector<int> ans;
      for(int i=0;i<intervals.size();i++){
        int l=0;
        int idx=-1;
        int r=intervals.size()-1;
        int res=INT_MAX;
        while(l <= r){
          int mid = l+(r-l)/2;
          if(arr[mid][0] >= intervals[i][1]){
            res = arr[mid][0];
            idx = arr[mid][1];
            r = mid-1;  
          }else if(arr[mid][0] < intervals[i][1]){
            l = mid+1;
          }
        }
        
        ans.push_back(idx);
      }
    
      return ans;
    }
};