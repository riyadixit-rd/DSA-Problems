class Solution {
public:
    int n;
    vector<int> suf;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        if (i >= n) return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int taken = suf[i] - suf[i + X];

            ans = max(ans, taken + suf[i + X] - solve(i + X, max(M, X)));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suf.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            suf[i] = piles[i] + suf[i + 1];

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};