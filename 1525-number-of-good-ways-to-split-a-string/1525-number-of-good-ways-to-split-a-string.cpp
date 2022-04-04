class Solution {
public:
    int numSplits(string s) {
      vector<int> ar(246,0),ar1(246,0);
        unordered_map<int,int> pre,suff;
      int cnt=0,cnt1=0,n=s.size()-1;  
      for(int i=0;i<s.size();i++){
        if(ar[s[i]] == 0){
            ar[s[i]] = 1;
            cnt+=1;
        }
        pre.insert({i,cnt});
        if(ar1[s[n-i]] == 0){
          ar1[s[n-i]] = 1;
          cnt1+=1;
        }
        suff.insert({n-i,cnt1});
      }
      int ans=0;
      for(int i=0;i<s.size()-1;i++){
        if(pre[i] == suff[i+1]){
          ans += 1;
        }
      }
      return ans;
    }
};