class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    dp[i]=max(dp[i],1+dp[j]);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};