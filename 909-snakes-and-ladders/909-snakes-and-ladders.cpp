class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int,int> mp;
        int step=1,leftToRight=1;
        for(int i=board.size()-1;i>=0;i--){
            if(leftToRight == 1){
          for(int j=0;j<board[0].size();j++){
              if(board[i][j] != -1){
              mp.insert({step,board[i][j]});
            }
            step++;
          }
            }else{
            for(int j=board[0].size()-1;j>=0;j--){
              if(board[i][j] != -1){
              mp.insert({step,board[i][j]}); 
            }
            step++;
                }     
            }
            leftToRight = !leftToRight;
        }
        queue<pair<int,int>> q;
        int r = board.size(),c=board[0].size();
        vector<int> visited(r*r + 1,0);
        q.push({1,0}); //position , step
        int ans = INT_MAX;
      while(!q.empty()){
         auto tp = q.front();
         q.pop();
         if(tp.first == r*r){
             ans = min(ans,tp.second);
         }
         for(int k=1;k<=6;k++){
             int step = k + tp.first;
             if(step > r*r) break;
             if(mp.find(step) != mp.end() && visited[mp[step]] == 0){
                 q.push({mp[step],tp.second+1});  
                 visited[mp[step]] = 1;
             }else if(step <= r*r && visited[step] == 0 && mp.find(step) == mp.end()){
                 q.push({step,tp.second+1});
             visited[step]=1;
             } 
      }
    }  
    return ans == INT_MAX ? -1 : ans;
    }
};