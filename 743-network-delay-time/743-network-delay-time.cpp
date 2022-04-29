class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> visited(n+1,0);
        vector<int> dist(n+1,INT_MAX);
        dist[0]=0;
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> > st;
        st.push({0,k});
        dist[k]=0;
        while(!st.empty()){
            int u = st.top().second;
            st.pop();
            if(visited[u] == 1) continue;
            visited[u] = 1;
            for(auto it:adj[u]){
                int v =  it.first;
                int w = it.second;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u]+ w;
                    st.push({dist[v] , v});
                }
                // visited[i] = 1;
            }
        }
        for(int i=0;i<=n;i++){
           cout<<dist[i]<<endl;
        }
        int ans = *max_element(dist.begin(),dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};