class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto c:words){
            if(F(c) == F(pattern)){
                res.push_back(c);
            }
        }
        return res;
    }
    string F(string w){
        unordered_map<char,int> mp;
        for(auto it:w){
            if(!mp.count(it)){
                mp[it] = mp.size();
            }
        }
        for(int i=0;i<w.size();i++){
            w[i] = 'a' + mp[w[i]];
        }
        return w;
    }
};