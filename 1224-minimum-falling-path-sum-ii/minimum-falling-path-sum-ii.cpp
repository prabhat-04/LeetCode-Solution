class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[0][i]=grid[0][i];
            
        }
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int temp = INT_MAX;
                for(int k=0;k<n;k++){
                    if(k!=j) temp = min(temp,dp[i-1][k]);
                }
                dp[i][j]=grid[i][j]+temp;
                if(i==n-1) ans = min(ans,dp[i][j]);
            }
        }
        return ans==INT_MAX?grid[0][0]:ans;
    }
};