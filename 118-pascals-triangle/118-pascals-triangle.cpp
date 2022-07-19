class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i,j;
      vector<vector<int>> vect;
      for(i=0;i<numRows;i++){
        vector<int>b;
        for(j=0;j<=i;j++){
          if(j == 0 || j == i){
            b.push_back(1);
          }else{
            b.push_back(vect[i-1][j-1] + vect[i-1][j]);
          }
      } 
        vect.push_back(b);
      }
      return vect;
    }
};