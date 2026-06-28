class Solution {
public:
    long long calc(vector<int>& nums, int k, bool mult) {
        const long long NEG = -(1LL << 60);

        long long dp0 = NEG, dp1 = NEG, dp2 = NEG;
        long long ans = NEG;

        for (int x : nums) {
            long long y;

            if (mult)
                y = 1LL * x * k;
            else
                y = (x >= 0 ? x / k : -((-x) / k));

            long long ndp0 = max(dp0 + x, 1LL * x);
            long long ndp1 = max({dp0 + y, 1LL * y, dp1 + y});
            long long ndp2 = max(dp1 + x, dp2 + x);

            dp0 = ndp0;
            dp1 = ndp1;
            dp2 = ndp2;

            ans = max({ans, dp0, dp1, dp2});
        }

        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(calc(nums, k, true), calc(nums, k, false));
    }
};