typedef pair<int,int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        
        priority_queue<pi> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int i=0;
        vector<int> ans;
        while(!pq.empty()){
            if(i <= k-1){
                auto pr = pq.top();
                ans.push_back(pr.second);
                pq.pop();
            }else{
                break;
            }
            i++;
        }
        return ans;
    }
};