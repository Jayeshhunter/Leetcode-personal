class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp,mp1;
        vector<int> ans;
        for(auto it:nums1){
            mp[it]++;
        }
        for(auto it:nums2){
            mp1[it]++;
        }
        for(auto it:mp){
            if(mp1[it.first]){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};