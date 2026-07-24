class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int x : nums) {
            for (int k = 2; k >= 0; k--) {
                for (int v = 0; v < MAXX; v++) {
                    if (dp[k][v])
                        dp[k + 1][v ^ x] = true;
                }
            }
        }

        vector<bool> vis(MAXX, false);

        // Triplets with repeated indices produce the element itself.
        for (int x : nums)
            vis[x] = true;

        // Triplets with three distinct indices.
        for (int v = 0; v < MAXX; v++)
            if (dp[3][v])
                vis[v] = true;

        int ans = 0;
        for (bool x : vis)
            ans += x;

        return ans;
    }
};