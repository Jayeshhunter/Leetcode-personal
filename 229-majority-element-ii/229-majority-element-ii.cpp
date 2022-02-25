class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int y=-1,z=-1,cy = 0,cz=0;
       for(auto x:nums){
         if(x==y){
           cy++;
         }else if(x == z){
           cz++;
         }else if(!cy){
           y = x; 
           cy=1;
         }else if(!cz){
           z = x;
           cz=1;
         }else{
           cz--;
           cy--;
         }
       } 
      cz=cy=0;
      vector<int>res;
      for(auto x:nums){
        if(x == y){
          cy++;
        }else if(x == z){
          cz++;
        }
      }
      if(cy > size(nums)/3){
        res.push_back(y);
      }
      if(cz > size(nums)/3){
        res.push_back(z);
      }
      return res;
    }
};