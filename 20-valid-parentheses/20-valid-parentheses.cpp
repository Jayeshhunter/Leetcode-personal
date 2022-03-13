class Solution {
public:
     bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
               //if the current character is opening bracket then take it in the stack
			   st.push(s[i]);
            }
            else if(s[i]==')'){
			//now if the current character is a closing bracket the pop out similar bracket if found at top else LIFO pattern is not followed and hence return false
                if(!st.empty()&&st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
			//now if the current character is a closing bracket the pop out similar bracket if found at top else LIFO pattern is not followed and hence return false
                if(!st.empty()&&st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
			//now if the current character is a closing bracket the pop out similar bracket if found at top else LIFO pattern is not followed and hence return false
                if(!st.empty()&&st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
		//finally if stack is empty so for each opening bracket we have a closing bracket hence return true else false
        return st.empty();
    }
};