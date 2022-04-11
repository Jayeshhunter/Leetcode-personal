class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int> mp;
        int sm=0;
        for(string it:emails){
            // auto pos = find(it.begin(),it.end(),'@');
            string tmp=it;
            size_t pos = it.find("@");
            it = it.substr(0,pos);
            // auto ps1=find(it.begin(),it.end(),'+');
            size_t pos1 = it.find("+");
            string ans;
            if(pos1 != string::npos){
                ans = it.substr(0,pos1);
                string ap = "";
                for(auto chk:ans){
                    if(chk != '.'){
                        ap += chk;
                    }
                }
                ans = ap;
                ans = ans + tmp.substr(pos);
                mp[ans]++;
            }else{
                ans=it;
                string ap = "";
                for(auto chk:ans){
                    if(chk != '.'){
                        ap += chk;
                    }
                }
                ans=ap;
                ans = ans + tmp.substr(pos);
                mp[ans]++;
            }
        }
        for(auto it:mp){
            sm++;
        }
        return sm;
    }
};