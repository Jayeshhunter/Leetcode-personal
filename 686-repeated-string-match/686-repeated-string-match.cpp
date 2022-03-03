class Solution {
public:
    int repeatedStringMatch(string a, string b) {
      int i=0,sz=a.size();
      string s="";
      int rp=1;
      while(rp++<=b.size()/a.size() + 2 && (s = s+a).find(b) == string::npos);
      if(s.find(b) != -1) return --rp;
      return -1;
    }
};