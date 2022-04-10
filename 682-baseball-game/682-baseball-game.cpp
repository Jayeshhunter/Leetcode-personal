class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        for(auto it:ops){
            if(it == "C"){
                ans.pop_back();
            }else if(it == "D"){
                int pv = ans.back();
                cout<<pv*2<<endl;
                ans.push_back(2*pv);
            }else if(it == "+"){
                int s1 = ans.back();
                ans.pop_back();
                int s2 = ans.back();
                int ns = s1+s2;
                ans.push_back(s1);
                ans.push_back(ns);
            }else{
                int vl = stoi(it);
                
                ans.push_back(vl);
            }
        }
        int acsum = 0;
        acsum = accumulate(ans.begin(),ans.end(),acsum);
        return acsum;
    }
};