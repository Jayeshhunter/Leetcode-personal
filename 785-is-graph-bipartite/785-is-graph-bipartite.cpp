class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        
        int r = graph.size();
        int c = graph[0].size();
        int sz = r*c;
        vector<int> colour(r,-1);
        int f = q.front();
    
        for(int i=0;i<r;i++){
            if(colour[i] != -1) continue;
            q.push(i);
            colour[i]=1;
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            int col = colour[tp];
            for(auto it:graph[tp]){
                if(colour[it] == -1){
                    colour[it] = col == 1 ? 0 : 1;
                    q.push(it);
                }else if(colour[it] == col){
                    return false;
                }
            }
        }
        }
        return true;
    }
};