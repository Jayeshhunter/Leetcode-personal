class Solution {
public:
    vector<vector<int>> ans;
    void permutate(vector<int>& nums,int left,int right){
        if(left == right){
            ans.push_back(nums);
            return;
        }
        for(int i=left;i<=right;i++){
            swap(nums[left],nums[i]);
            permutate(nums,left+1,right);
            swap(nums[left],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1) {
            ans.push_back(nums);
            return ans;
        }
        permutate(nums,0,nums.size()-1);
        return ans;
    }
};