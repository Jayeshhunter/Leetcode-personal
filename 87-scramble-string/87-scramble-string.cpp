class Solution {
public:
    unordered_map<string,bool> mp;
    bool solve(string a, string b){
        
        if(a.size() != b.size()) return false;
       
        string key = a + " " + b;
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        if(a == b) return mp[key]=true;
        if(a.size() <= 1) return mp[key]=false;
    
        int n = a.size();
        for(int i=1;i<=n-1;i++){
            if((solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i),b.substr(0,n-i)) == true) || (solve(a.substr(0,i),b.substr(0,i)) == true && solve(a.substr(i),b.substr(i)) == true) ){
                return mp[key]=true;
            }
        }
        return mp[key] = false;
    } 
    bool isScramble(string s1, string s2) {
        if(s1 == "" && s2 == "") return true;
        if(s1.size() - s2.size() != 0) return false;
        return solve(s1,s2);
    }
};