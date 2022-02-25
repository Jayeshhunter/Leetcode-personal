class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i;
      vector<int> arr(246,-1);
      int start = -1,maxLen = 0;
      for(i=0;i<s.length();i++){
        if(arr[s[i]] > start){
          start = arr[s[i]];
        }
        arr[s[i]] = i;
        maxLen = max(maxLen,i-start);
      }
      return maxLen;
    }
};