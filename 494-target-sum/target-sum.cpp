class Solution {
    void solve(vector<int> &nums,int &target,int ind,int sum,int &ans){
        if(ind>=nums.size()){
            if(sum==target) ans++;
            return;
        }
        sum+=nums[ind];
        solve(nums,target,ind+1,sum,ans);
        sum-=nums[ind];
        sum-=nums[ind];
        solve(nums,target,ind+1,sum,ans);
        sum+=nums[ind];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0,ans=0;
        solve(nums,target,0,sum,ans);
        return ans;
    }
};