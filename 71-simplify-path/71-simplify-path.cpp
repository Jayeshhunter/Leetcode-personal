class Solution {
public:
    string simplifyPath(string path) {
        vector<string> track;
        stringstream ss(path);
      string tmp;
        while(getline(ss,tmp,'/')){
          if(tmp == "." || tmp == "") continue;
          if(tmp == ".." && !track.empty()){
            track.pop_back();
          }
          if(tmp != ".."){
            track.push_back(tmp);
          }
        }
      string res;
      for(auto st:track) res += "/"+st;
      return res.empty()?"/":res;
    }
};