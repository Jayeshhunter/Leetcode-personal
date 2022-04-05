class Solution {
public:
    int maxArea(vector<int>& height) {
      
      int i=0,j=height.size()-1,maxArea=0;
      while(i<j){
        maxArea = max(maxArea,(j-i)*min(height[i],height[j]));
        height[i]<height[j]?i++:j--;
      }
      return maxArea;
    }
};