class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0,sum=0;
      sum = accumulate(weights.begin(),weights.end(),sum);
      int right = sum;
      int res = INT_MAX;
      while(left<=right){
        int mid = left + (right-left)/2;
        if(isValid(weights,days,mid) == true){
          res = min(res,mid);
          right = mid-1;
        }else{
          left = mid+1;
        }
      }
      return res;
    }
  bool isValid(vector<int>& weights,int days,int mid){
    int limit = 1;
    int curr = 0;
    for(int i=0;i<weights.size();i++){
      if(weights[i] > mid) return false;
      if(weights[i] + curr > mid){
        limit++;
        curr = weights[i];
        if(limit > days) return false;
      }else{
        curr += weights[i];
      }
    }
    return true;
  }
};