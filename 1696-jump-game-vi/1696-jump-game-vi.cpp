class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
     int curr=nums[0];
      q.push_front({0,curr});
      for(int j=1;j<nums.size();j++){   
        while(q.size() > 0 && j - q.front().first > k) {
                q.pop_front();
            }
        curr = q.front().second + nums[j];
        while(!q.empty() && q.back().second < curr){
          q.pop_back();         
        }
        q.push_back({j,curr}); 
      }
      return q.back().second;
    }
};