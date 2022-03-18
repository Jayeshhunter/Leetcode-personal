class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
      int sz = s.size();  
      vector<int> arr(sz,0);
      for(int i=0;i<sz;i++){
           arr[i] = traverse(n,s,startPos[0],startPos[1],i);
      }
      return arr;
    }
  int traverse(int n,string s,int row,int col,int pos){
    int ans=0;
    for(int i=pos;i<s.size();i++){
      if(s[i] == 'R'){
        col++;
      }else if(s[i] == 'L'){
        col--;
      }else if(s[i] == 'U'){
        row--;
      }else if(s[i] == 'D'){
        row++;
      }
      if(row < 0 || col <0 || row>=n || col>=n){
        return ans;
      }
      ans++;
    }
    return ans;
  }
};