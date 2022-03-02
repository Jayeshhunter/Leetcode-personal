class Solution {
public:
  
  int chPres(char ch,int k,string t){
    while(k<t.size()){
      if(ch == t[k]){
        return k;
      }
      k++;
    }
    return -1;
  }
    bool isSubsequence(string s, string t) {
        int i;
      int k=0;
      for(i=0;i<s.size();i++){
        if(chPres(s[i],k,t) != -1){
          k = chPres(s[i],k,t)+1;
        }else{
          return false;
        }
      }
         return true;
    }
};