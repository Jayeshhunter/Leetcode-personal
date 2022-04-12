class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size(),c=board[0].size();
        int k[][2] = {{-1,-1},{-1,0},{0,1},{-1,1},{0,-1},{1,0},{1,-1},{1,1}};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                    int sm=0;
                 for(auto it:k){
                     int x = i+it[0];
                     int y = j+it[1];
                     if(x<0 || y<0 || x>= r || y>=c) continue;
                     if(board[x][y] & 1) sm += 1;
                 }
                if(board[i][j] == 0){
                    if(sm == 3){
                        board[i][j] = 2;
                    }
                }else{
                    if(sm < 2 || sm > 3) board[i][j]=1;
                    if(sm ==2 || sm == 3) board[i][j] = 3;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                board[i][j] >>= 1;
            }
        }
    }
};