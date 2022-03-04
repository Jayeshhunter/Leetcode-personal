class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
      st.push(INT_MAX);
      int res=0;
      for(int tr:arr){
        while(st.top()<=tr){
          int tp = st.top();
          st.pop();
          res += tp* min(st.top(),tr);
        }
        st.push(tr);
      }
      while(st.top() != INT_MAX){
        int tp=st.top();
        st.pop();
        if(st.top() != INT_MAX){
        res += st.top()*tp;
        }else{
          break;
        }
      }
      return res;
    }
};