class Solution {
    int ans;
    void solve(int i,vector<int> &nums,int curr){
        if(i==nums.size()){
            ans+=curr;
            return;
        }
        solve(i+1,nums,curr);
        curr^=nums[i];
        solve(i+1,nums,curr);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        ans =0;
        solve(0,nums,0);
        return ans;
    }
};