class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
              priority_queue<int,vector<int>,greater<int>> pq;
        int mod = pow(10,9) + 7;
        for(auto it:nums){
            pq.push(it);
        }
        while(k--){
            int tp = pq.top();
            pq.pop();
            pq.push(tp+1);
        }
        long long int ans=1;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            ans = (ans*top)%mod;
        }
        return ans;
    }
};