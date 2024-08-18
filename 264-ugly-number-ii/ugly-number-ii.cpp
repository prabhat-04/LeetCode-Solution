class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;

        int index2 = 0, index3=0,index5=0;
        int next2=2,next3=3,next5=5;

        for(int i=1;i<n;i++){
            dp[i] = min(next2,min(next3,next5));
            if(dp[i]==next2){
                index2++;
                next2 = dp[index2] * 2;
            }

            if(dp[i]==next3){
                index3++;
                next3 = dp[index3] * 3;
            }

            if(dp[i]==next5){
                index5++;
                next5 = dp[index5] * 5;
            }
        }

        return dp[n-1];
    }
};