class Solution {
    void solve(vector<int> &arr,int target,int sum,int idx,vector<int> curr,vector<vector<int>> &result){
        int n = arr.size();
        if(sum==target){
            result.push_back(curr);
            return;
        }
        if(idx>=n || sum>target) return;
        
        for(int i=idx;i<n;i++){
            if(i !=idx && arr[i]==arr[i-1]) 
                continue;   
            sum+=arr[i];
            curr.push_back(arr[i]);
            solve(arr,target,sum,i+1,curr,result);
            curr.pop_back();
            sum-=arr[i];
        }
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,0,curr,result);
        return result;
    }
};