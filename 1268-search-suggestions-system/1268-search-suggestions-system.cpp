class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto it = products.begin();
        sort(it,products.end());
        vector<vector<string>> ans;
        string src = "";
        for(auto ch:searchWord){
            src += ch;
            it = lower_bound(it,products.end(),src);
            vector<string> arr;
            for(int i=0;i<3 && it+i != products.end();i++){
                string &s = *(it+i);
                if(s.find(src)) break;
                arr.push_back(s);
                
            }
            ans.push_back(arr);
        }
        return ans;
    }
};