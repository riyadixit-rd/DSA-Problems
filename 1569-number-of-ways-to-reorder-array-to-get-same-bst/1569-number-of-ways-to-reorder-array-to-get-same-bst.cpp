class Solution {
    static const int MOD = 1e9 + 7;
    long long C[1001][1001]{};

    int dfs(vector<int>& a) {
        int n = a.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[0]) left.push_back(a[i]);
            else right.push_back(a[i]);
        }

        long long ways = C[n - 1][left.size()];
        ways = ways * dfs(left) % MOD;
        ways = ways * dfs(right) % MOD;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};