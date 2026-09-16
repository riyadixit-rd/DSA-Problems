class Solution {
    static final int MOD = 1000000007;

    public int numberOfSets(int n, int k) {
        long[][] dp = new long[k + 1][n];

        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int j = 1; j <= k; j++) {
            long sum = 0;

            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    sum = (sum + dp[j - 1][i - 1]) % MOD;
                }

                dp[j][i] = (dp[j][i] + sum) % MOD;

                if (i > 0) {
                    dp[j][i] = (dp[j][i] + dp[j][i - 1]) % MOD;
                }
            }
        }

        return (int) dp[k][n - 1];
    }
}