class Pos{
  int n;
  int pos;
  Pos(int n, int pos){
    this.n = n;
    this.pos = pos;
  }
}
class Solution {
    public int snakesAndLadders(int[][] board) {
      HashMap<Integer, Integer> map = new HashMap<>();
      int r = board.length;
      int c = board[0].length;
      int step = 1;
      boolean leftToRight = true;
      for(int i = r-1; i >= 0; i--){
        if(leftToRight){
          for(int j = 0; j < c; j++){
            if(board[i][j] != -1){
              map.put(step, board[i][j]);
            }
          step++;
          }
        }
        else{
          for(int j = c-1; j>= 0; j--){
            if(board[i][j] != -1){
              map.put(step, board[i][j]);
            }
            step++;
          }
        }
        leftToRight = !leftToRight;
      }
      int ans = Integer.MAX_VALUE;
      boolean[] visited = new boolean[r*r+1];
      Queue<Pos> queue = new LinkedList<>();
      queue.offer(new Pos(1, 0));
      while(!queue.isEmpty()){
        Pos obj = queue.poll();
        if(obj.n == r*r){
          ans = Math.min(ans, obj.pos);
        }
        for(int k = 1; k <= 6; k++){
          int nc = obj.n + k;
          if(map.containsKey(nc) && !visited[map.get(nc)]){
            queue.offer(new Pos(map.get(nc), obj.pos+1));
            visited[map.get(nc)] = true;
          }
          else if(nc <= r*r && !visited[nc] && !map.containsKey(nc)){
            queue.offer(new Pos(nc, obj.pos+1));
            visited[nc] = true;
          }
        }
     }
     return (ans == Integer.MAX_VALUE) ? -1 : ans;      
    }
}