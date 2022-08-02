class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n= matrix.size();
      int lo=matrix[0][0],hi=matrix[n-1][n-1],mid,count,temp;
      while(lo<hi){
        temp = n-1;
        count =0;
        mid = lo + (hi-lo)/2;
        for(int i=0;i<n;i++){
          while(temp >= 0 && matrix[i][temp] > mid) temp--;
          count += temp + 1;
        }
        if(count<k) lo=mid+1;
        else hi = mid;
      } 
      return lo;
    }
};