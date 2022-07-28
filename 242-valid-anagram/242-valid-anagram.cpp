class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.length() != t.length()){
        return false;
      }
       unordered_map<char,int> arr;
      int i,j,count=0;
      for(i=0;i<s.length();i++){
        if(arr[s[i]] == 0){
          count++;
          arr[s[i]] = 1;
        }else{
          arr[s[i]]++;
        }
      }
      for(i=0;i<t.length();i++){
        arr[t[i]]--;
        if(arr[t[i]] == 0){
          count--;
        }
      }
      if(count == 0){
        return true;
      }else{
        return false;
      }
    }
};