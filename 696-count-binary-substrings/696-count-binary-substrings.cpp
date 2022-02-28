class Solution {
public:
  int ans=0;
  void count(string s){
    stack<int> st;
   int flag=0;
    for(int i=0;i<s.size();i++){
      if(s[i] == '0'){
        if(flag == 1){
          st.push(-1);
          flag=0;
        }
        st.push(i);
      }else{
        if(!st.empty() && st.top() != -1){
        st.pop();
          flag=1;
        ans++;
        }
      }
    }
  }
    int countBinarySubstrings(string s) {
      count(s);
      reverse(s.begin(),s.end());
      count(s);
      return ans;
    }
};