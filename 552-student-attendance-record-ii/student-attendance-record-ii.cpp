class Solution {
public:
    const int MOD = 1e9 + 7;

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }

            for (int k = 0; k < 3; ++k) {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }

            for (int j = 0; j < 2; ++j) {
                for (int k = 1; k < 3; ++k) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
        }

        int ans = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                ans = (ans + dp[n][j][k]) % MOD;
            }
        }
        return ans;
    }
};