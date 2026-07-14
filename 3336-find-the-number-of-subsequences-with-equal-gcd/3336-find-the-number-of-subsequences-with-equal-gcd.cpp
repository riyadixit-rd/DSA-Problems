class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        const int M = 200;

        vector<vector<long long>> dp(M + 1,
                                     vector<long long>(M + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            auto ndp = dp;

            for (int g1 = 0; g1 <= M; g1++) {
                for (int g2 = 0; g2 <= M; g2++) {
                    long long ways = dp[g1][g2];
                    if (!ways) continue;

                    int ng1 = (g1 == 0 ? x : gcd(g1, x));
                    int ng2 = (g2 == 0 ? x : gcd(g2, x));

                    ndp[ng1][g2] =
                        (ndp[ng1][g2] + ways) % MOD;

                    ndp[g1][ng2] =
                        (ndp[g1][ng2] + ways) % MOD;
                }
            }

            dp = move(ndp);
        }

        long long ans = 0;

        for (int g = 1; g <= M; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};