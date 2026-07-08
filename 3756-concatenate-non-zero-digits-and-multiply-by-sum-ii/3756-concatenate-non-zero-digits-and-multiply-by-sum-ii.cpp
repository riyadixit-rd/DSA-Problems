class Solution {
public:
    static const long long MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> pref(n + 1, 0);
        vector<long long> sum(n + 1, 0);
        vector<long long> cnt(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            sum[i + 1] = sum[i];
            cnt[i + 1] = cnt[i];

            int d = s[i] - '0';

            if (d != 0) {
                pref[i + 1] = (pref[i] * 10 + d) % MOD;
                sum[i + 1] += d;
                cnt[i + 1]++;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long digits =
                cnt[r + 1] - cnt[l];

            long long digitSum =
                sum[r + 1] - sum[l];

            long long x =
                (pref[r + 1]
                 - pref[l] * pow10[digits] % MOD
                 + MOD) % MOD;

            long long cur =
                (x * (digitSum % MOD)) % MOD;

            ans.push_back((int)cur);
        }

        return ans;
    }
};