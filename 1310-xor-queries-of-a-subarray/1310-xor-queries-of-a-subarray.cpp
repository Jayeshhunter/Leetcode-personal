class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
     //prefix sum concept
      for(int i=1;i<arr.size();i++){
        arr[i] ^= arr[i-1];
      }
      vector<int> res;
      for(auto i:queries){
        res.push_back(i[0] > 0 ? arr[i[0]-1] ^ arr[i[1]] : arr[i[1]]);
      }
      return res;
    }
};