class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int row = grid.size();
if (row == 0) return -1;
int col = grid[0].size();
if (col == 0 ) return -1;
       if (grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        while(!q.empty()){
            auto c = q.front();
            q.pop();
            int x = c.first,y=c.second;
            if( x == n-1 && y == n-1) return grid[x][y];
            for(auto it:directions){
                int x1=x+it[0],y1=it[1]+y;
                if(x1 >= 0 && y1 >= 0 && x1 < n && y1 < n && grid[x1][y1] == 0){
                    q.push({x1,y1});
                    grid[x1][y1] = grid[x][y] + 1;
                }
            }
        }
        return -1;
    }
};