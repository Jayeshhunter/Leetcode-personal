class Solution {
public:
    long noofVal(int mid,vector<int>& candies){
        long no=0;
        for(auto it:candies){
            
                no += (it/mid);
            
        }
        return no;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        int left = 0;
        int right = 1e7;
        
        
        while(left < right){
            long mid = (left + right + 1)/2;
            long nv = noofVal(mid,candies);
            if(nv < k){
                right = mid-1;
            }else{
                left = mid;
            }
        }
        return left;
    }
};