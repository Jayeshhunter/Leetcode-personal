class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
    
      int finalState = (1<<graph.size())-1; 
      queue<vector<int>> q;
set<pair<int,int>> st;
      for(int i=0;i<graph.size();i++){
        vector<int> v(3,0);
        int cost=0,bitst=(1<<i);
        v[0]=cost;
        v[1]=i;
        v[2]=bitst;
        q.push(v);
        st.insert({i,bitst});
      }
      int ans=0;
  
      while(!q.empty()){
       auto p = q.front();
        q.pop();
       //check if the bit is the final bit or not
        if(p[2] == finalState){
          ans = p[0];
          break;
        } 
        for(auto it:graph[p[1]]){
          int mask = p[2] | (1<<it);
          if(st.find({it,mask}) == st.end()){
            st.insert({it,mask});
            vector<int>v(3,0);
            v[0]=p[0]+1;
            v[1]=it;
            v[2]=mask;
            q.push(v);
          }
        }
      }
      return ans;
    }
};