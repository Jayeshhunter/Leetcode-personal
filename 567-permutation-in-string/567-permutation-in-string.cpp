class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26,0);
        for(char ch:s1) cnt[ch-'a']++;
        int i=0,j=0,count=s1.size();
        while(j<s2.size()){
            if(cnt[s2[j++]-'a']-- > 0){
                count--;
            }
            if(count == 0) return true;
            if(j-i == s1.size() && cnt[s2[i++]-'a']++ >= 0) count++;
        }
        return false;
    }
};