class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
vector<vector<double>> matrix(105,vector<double>(105,0));
      queue<pair<int,int>> q;
      q.push({0,0});
      matrix[0][0]=poured;
      int cnt=0;
      while(!q.empty() && cnt<100){
        int sz = q.size();
        cnt += 1;
        while(sz--){
          int x = q.front().first ;
          int y = q.front().second;
          q.pop();
          
          double p = matrix[x][y];
          if(p > 1){
            matrix[x][y]=1;
            p-=1;
            matrix[x+1][y] += p/2;
            matrix[x+1][y+1] += p/2;
            q.push({x+1,y});
            q.push({x+1,y+1});
          }
          if(x == query_row && y == query_glass) return matrix[x][y];
        }
      }
      return matrix[query_row][query_glass];
    }
};