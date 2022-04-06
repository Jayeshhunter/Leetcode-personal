class Solution {
public:
    int threeSumMulti(vector<int>& arr, int t) {
      sort(arr.begin(),arr.end());
      int n = arr.size();
      unordered_map<int,long> mp;
      for(auto it:arr){
          mp[it]++;
      }
      long ans=0;
      long mod = 1e9+7;
      for(auto it1:mp){
        if(it1.first > t) continue;
        for(auto it2:mp){
         int x=it1.first,y=it2.first,z=t-x-y;
          if(mp.find(z)!=mp.end()){
         if(x==y && y == z){
           ans += mp[x]*(mp[x]-1)*(mp[x]-2) / 6;
         }else if(x == y && y!=z){
           ans += mp[x]*(mp[x]-1)/2 *mp[z]; 
         }else if(x < y && y<z){
           ans += mp[x]*mp[y]*mp[z];
         }
         ans = ans%mod;
          }
       }
        
      }
      return ans;
    }
};