class Solution {
    int help(vector<int>& coins, int amount, vector<int>& dp){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int ans = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int x = help(coins,amount-coins[i],dp);
            x = (x==INT_MAX?INT_MAX:x+1);
            ans = min(ans,x);
        }
        dp[amount]=ans;
        return ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = help(coins,amount,dp);
        return ans==INT_MAX?-1:ans;
    }
};