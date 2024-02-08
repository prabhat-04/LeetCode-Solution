class Solution {
public:
    int numSquares(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i*i<=n;i++){
            dp[i*i]=1;
        }
        for(int i=2;i<=n;i++){
            if(dp[i]!=1){
                int x=1,y=i-1;
                while(x<=y){
                    dp[i] = min(dp[i],dp[x]+dp[y]);
                    x++;
                    y--;
                }
            }
        }
        // for(int x:dp)
        //     cout<<x<<" ";
        return dp[n];
    }
};