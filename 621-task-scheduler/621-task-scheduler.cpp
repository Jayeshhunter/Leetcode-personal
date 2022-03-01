class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        unordered_map<char,int> mp;
      int count=0;
      for(char ch:tasks) mp[ch]++;
      priority_queue<int> q;
      for(auto i:mp){
        q.push(i.second);
      }
      while(!q.empty()){
        vector<int> temp;
        for(int i=0;i<=n;i++){
          if(!q.empty()){
            temp.push_back(q.top());
            q.pop();
          }
        }
        for(int i:temp){
          if(--i > 0){
            q.push(i);
          }
        }
        count += q.empty() == true ? temp.size() : n+1;
      }
      return count;
    }
};