class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    priority_queue<pair<int,int>> p; 
        for(auto it:boxTypes){
            p.push({it[1],it[0]});
        }
        int tot=0,sum=0;
        while(tot <= truckSize && p.size() > 0){
            auto it = p.top();
            if(tot+it.second <= truckSize){
                tot += it.second;
                sum += it.first * it.second;
            }else{
                int res = truckSize-tot;
                sum += it.first * res;
                tot = truckSize + 1;
            }
            p.pop();
        }
        return sum;
    }
};