class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      vector<int>front(k);
      vector<int>back(k);
      int n = cardPoints.size();
      front[0] = cardPoints[0];
      back[0] = cardPoints[n-1];
      for(int i=1;i<k;i++){
        front[i] = cardPoints[i] + front[i-1];
        back[i] = cardPoints[n-i-1] + back[i-1];
      }
      int max = back[k-1];
      if(max < front[k-1]){
        max = front[k-1];
      }
      for(int i=0;i<k-1;i++){
        int y = front[i]+back[k-i-2];
        if(y>max){
          max = y;
        }
      }
      return max;
    }
};