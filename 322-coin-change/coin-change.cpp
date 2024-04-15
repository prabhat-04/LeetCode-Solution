class Solution {
private:
    int solve(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int i=1 ; i<=amount ; i++)
        {
            for(int j=0 ; j<coins.size() ; j++)
            {
                if((i-coins[j])>=0 && dp[i-coins[j]]!=INT_MAX)
                {
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());

        if(solve(coins, amount)==INT_MAX)
            return -1;
        return solve(coins, amount);
    }
};