class Solution {
public:
    int dp[21][21];

    int solve(vector<int>& nums, int l, int r) {
        if (l == r)
            return nums[l];

        if (dp[l][r] != INT_MIN)
            return dp[l][r];

        int takeLeft = nums[l] - solve(nums, l + 1, r);
        int takeRight = nums[r] - solve(nums, l, r - 1);

        return dp[l][r] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < 21; i++)
            for (int j = 0; j < 21; j++)
                dp[i][j] = INT_MIN;

        return solve(nums, 0, n - 1) >= 0;
    }
};