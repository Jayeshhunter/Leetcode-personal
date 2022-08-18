class Solution {
public:
    int minSetSize(vector<int>& arr) {
         unordered_map<int,int> cnt;
        for(int i:arr){
            ++cnt[i];
        }
        vector<int> frequencies;
        for(auto [_,freq]:cnt){
            frequencies.push_back(freq);
        }
        sort(frequencies.begin(),frequencies.end());
        int removed=0,end=frequencies.size()-1,ans=0,half=arr.size()/2;
        while(removed < half){
            ans+=1;
            removed += frequencies[end--];
        }
        return ans;
    }
};