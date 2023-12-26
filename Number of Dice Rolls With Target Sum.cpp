class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: one way to get a sum of 0 with 0 dice
        dp[0][0] = 1;

        // Dynamic programming
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int num = 1; num <= k; ++num) {
                    if (j - num >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - num]) % MOD;
                    }
                }
            }
        }
        return dp[n][target];
    }
};
