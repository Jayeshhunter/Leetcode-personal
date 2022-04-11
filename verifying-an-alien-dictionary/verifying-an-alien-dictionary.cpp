class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=1;i<words.size();i++){
            string s1=words[i-1],s2=words[i];
            int j=0;
            while(j<s1.size() && j<s2.size() && s1[j] == s2[j]){
                j++;
            }
            if(j < s1.size() && j < s2.size()){
                size_t f1 = order.find(s1[j]),f2=order.find(s2[j]);
                if(f1 <= f2){
                    continue;
                }else{
                    return false;
                }
            }else{
                if(s1.size() < s2.size()){
                    continue;
                }else if(s1 == s2){
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};