class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        if(!matrix.size() || !matrix[0].size()){
          return false;
        }
      int l=0,r=matrix.size()-1;
      int mid =0;
      while(l<r){
        mid = (l + r)/2;
        if(matrix[mid][0] > t){
          r = mid-1;
        }
        else if(matrix[mid].back() < t){
          l = mid+1;
        }
        else{
          l = mid;
          break;
        }
      }
      int row;
      row = l;
      l=0;
      r = matrix[0].size()-1;
      mid=0;
      while(l<=r){
        mid = (l+r)/2;
        if(t < matrix[row][mid]){
          r = mid-1;
        }else if(t > matrix[row][mid]){
          l = mid+1;
        }else{
           return true;
        }
      }
      return false;
    }
};