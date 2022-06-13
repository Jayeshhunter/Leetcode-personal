class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      vector<int>minSum(triangle.back());
      for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
          minSum[j] = min(minSum[j],minSum[j+1]) + triangle[i][j];
        }
      }
      return minSum[0];     
    }
};