class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int sz = scores.size();
        vector<vector<int>> adj(sz);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(auto &l : adj) {
            partial_sort(begin(l), begin(l) + min((int)l.size(), 3), end(l), [&](int i, int j){ return scores[i] > scores[j]; });
            l.resize(min((int)l.size(), 3));
         }
        
        int ans = INT_MIN;
        for(auto it:edges){
            for(int x:adj[it[0]]){
                for(int y:adj[it[1]]){
                    if (x != it[1] && y != it[0] && x != y)
                        ans = max(ans, scores[it[0]] + scores[it[1]] + scores[x] + scores[y]);
                }
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};