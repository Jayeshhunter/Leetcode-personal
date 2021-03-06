class Solution {
public:
    int arr[100000];
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> pairs;
        for(int i=0;i<nums.size();i++){
            pairs.push_back({nums[i],i});
        }
        
        mergeSort(pairs,0,nums.size()-1);
        vector<int> res(nums.size());
        for(int i=0;i<nums.size();i++){
            res[i] = arr[i];
        }
        return res;
    }
    void mergeSort(vector<pair<int,int>>& pairs,int low,int high){
        int mid = (low+high)/2;
        if(low<high){
            mergeSort(pairs,low,mid);
            mergeSort(pairs,mid+1,high);
            merge(pairs,low,mid+1,high);
        }
    }
    void merge(vector<pair<int,int>>& pairs,int low,int mid,int high){
        int i=low;
        int j=mid;
        int count=0;
        int k=0;
        vector<pair<int,int>> tmp(high-low+1);
        while(i<=mid-1 && j <= high){
            if(pairs[i].first <= pairs[j].first){
                arr[pairs[i].second] += count;
                tmp[k++] = {pairs[i++]};
            }else{
                count++;
                tmp[k++] = {pairs[j++]};
            }
        }
        while(i<=mid-1){
            arr[pairs[i].second] += count;
            tmp[k++] = {pairs[i++]};
        }
        while(j<=high){
            tmp[k++] = {pairs[j++]};
        }
        for(int i=0;i<k;i++){
            pairs[low++] = tmp[i];
        }
    }
};