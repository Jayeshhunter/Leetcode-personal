

class Solution {
public:
    #define ll long long
    ll dp[105][25][104];
// index , prev , target
// if by the same index as prev then dont decrease target
// recursion tree for cost of painting and caching
    long long solve(vector<int>& houses,vector<vector<int>>& cost,ll index,ll prev,ll m,ll n,ll target){
        if(target < 0) return INT_MAX;
        if(index == m) {
            if(target == 0){
                return 0;
            }
            return INT_MAX;
        }
        if(houses[index] != 0) return dp[index][prev][target] = solve(houses,cost,index+1,houses[index],m,n,target - (prev != houses[index])); 
        if(dp[index][prev][target] != -1) return dp[index][prev][target];
        ll ans=INT_MAX;
        for(int i=1;i<=n;i++){
            ans = min(ans,cost[index][i-1]+solve(houses,cost,index+1,i,m,n,target-(prev!=i)));
        }
        return dp[index][prev][target] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        ll ans = solve(houses,cost,0,n+1,m,n,target);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
        }
};