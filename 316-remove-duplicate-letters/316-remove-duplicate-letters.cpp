class Solution {
public:
    string removeDuplicateLetters(string s) {
      vector<int>chval(256,0);
      vector<bool>visited(256,false);
      string result = "0";
      for(char ch:s){
        chval[ch]++;
      }
      for(char ch:s){
        chval[ch]--;
        if(visited[ch])continue;
        while(ch < result.back() && chval[result.back()]){
          visited[result.back()] = false;
          result.pop_back();
        }
        result+=ch;
        visited[ch] = true;
        
      }
      return result.substr(1);
    }
};