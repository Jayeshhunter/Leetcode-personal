class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> umap;
        int i,res=-1;
      for(i=0;i<s.length();i++){
        umap[s[i]]++;
      }
      for(i=0;i<s.length();i++){
        if(umap[s[i]] == 1){
          res = i;
          break;
        }
      }
      return res;
    }
};