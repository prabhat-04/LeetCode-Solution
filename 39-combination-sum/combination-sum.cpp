class Solution {
    void solve(vector<int> &arr,int target,int i,vector<int>&temp,vector<vector<int>> &ans){
        if(target<0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<arr.size();j++){
            temp.push_back(arr[j]);
            solve(arr,target-arr[j],j,temp,ans);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr,target,0,temp,ans);
        return ans;
    }
};