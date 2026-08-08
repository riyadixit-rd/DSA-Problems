#include <vector>

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        long long MOD = 1e9 + 7;
        
        // Base states:
        // dp[1] = 1, dp[2] = 2, dp[3] = 5
        long long dp1 = 1; 
        long long dp2 = 2; 
        long long dp3 = 5; 

        if (n == 3) return dp3;

        for (int i = 4; i <= n; ++i) {
            long long current = (2 * dp3 + dp1) % MOD;
            dp1 = dp2;
            dp2 = dp3;
            dp3 = current;
        }

        return dp3;
    }
};