class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
          
        int m = heights.size();
        int n = heights[0].size();
        int dir[5] = {-1,0,1,0,-1};
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<int>>efforts(m,vector<int>(n,INT_MAX));
        pq.push({0,0});
        while(!pq.empty()){
            int effort = pq.top().first;
            int x = pq.top().second/100;
            int y = pq.top().second%100;
            pq.pop();
            if(x == m-1 && y == n-1) return effort;
            if(effort >= efforts[x][y]) continue;
            efforts[x][y] = effort;
            for(int i=0;i<4;i++){
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                int n_effort = max(effort,abs(heights[nx][ny]-heights[x][y]));
                int ind = nx*100 + ny;
                pq.push({n_effort,ind});
            }
        }
        return -1;
    }
}; 
// 1 1
// 1*100 + 1 = 101
    